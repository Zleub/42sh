/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_pa_translate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 13:15:36 by gbir              #+#    #+#             */
/*   Updated: 2014/02/26 07:59:01 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "sh.h"
#include "libft.h"
#include <stdlib.h>

static t_lx_arg	*lx_pa_firstrule(char *arg, t_lx_line *line, int i)
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

t_lx_rule		*lx_pa_translate(t_lx_line *line)
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
/*	tmp = ret;
	tmp->first = lx_pa_firstrule();
	while ((tmp = tmp->next))
		tmp->first = lx_pa_firstrule(line, ++i);
	allfree(3, line->key, line->arg, line);
	while ((line = line->next))
		allfree(3, line->key, line->arg, line);
*/	return (ret);
}
