/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_pa_translate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 13:15:36 by gbir              #+#    #+#             */
/*   Updated: 2014/02/26 19:56:42 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "sh.h"
#include "libft.h"
#include <stdlib.h>

static t_lx_arg		*lx_pa_firstrule(char *arg, t_lx_line *line, int i)
{
	t_lx_arg	*ret;

	ret = NULL;
//	printf("%s\n", arg);
	while (*arg && (ft_iswhispa(*arg) || *arg == '|' || *arg == ','))
		++arg;
	if (*arg == ';' || !*arg)
		return (ret);
//	printf("    %.4s\n", arg);
	if (*arg == '"')
		ret = lx_pa_argstr(&arg);
	else if (*arg == '[' || i == 1)
	{
		++arg;
		ret = lx_pa_argexp(&arg);
		i = (*(arg + 1) && *(arg + 1) == ']') ? 0 : 1;
		if (*(arg + 1) == ']')
			arg += 2;
	}
	else
		ret = lx_pa_argrule(&arg, line);
	ret->next = lx_pa_firstrule(arg, line, i);
	return (ret);
}

static t_lx_rule		*lx_pa_link(t_lx_rule *first, int i)
{
	int			tmp;

	tmp = 0;
	while (tmp++ < i)
		first = first->next;
	return (first);
}

static t_lx_rule	*lx_pa_classification(t_lx_line *line, t_lx_rule *first)
{
	t_lx_rule	*tmp;
	t_lx_rule	*ret;
	t_lx_arg	*arg;

	ret = NULL;
	tmp = first;
	while (line)
	{
		if (ft_strncmp(line->key, "main", 4) == 0 && (ret = tmp))
			break ;
		tmp = tmp->next;
		line = line->next;
	}
	if (!ret)
		exit(0);//no main found
	tmp = first;
	while (tmp)
	{
		puts("looool");
		arg = tmp->first;
		while (arg)
		{
			if (arg->type == 3 || arg->type == 4)
				arg->link = lx_pa_link(first, arg->rule);
			arg = arg->next;
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_lx_rule			*lx_pa_translate(t_lx_line *line)
{
	t_lx_line	*cur;
	t_lx_rule	*ret;
	t_lx_rule	*tmp;

	tmp = ret = malloc(sizeof(t_lx_rule));
	cur = line;
//	printf("==%p\n", line);
	while (cur)
	{
//		printf("key = %.5s  arg = %.5s    %p\n", cur->key, cur->arg, cur);
//		printf("%p  %.5s\n", cur, cur->key);
		if (cur->arg)
			tmp->first = lx_pa_firstrule(cur->arg + 1, line, 0);
		tmp->next = NULL;
		cur = cur->next;
		if (cur)
			tmp = tmp->next = malloc(sizeof(t_lx_rule));
	}
	lx_pa_classification(line, ret);
	return (ret);
}
