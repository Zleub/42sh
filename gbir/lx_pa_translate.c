/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_pa_translate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 13:15:36 by gbir              #+#    #+#             */
/*   Updated: 2014/02/18 21:12:20 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "sh.h"
#include "libft.h"
#include <stdlib.h>

static t_lx_arg	*lx_pa_firstrule(char *arg)
{
	t_lx_arg	*ret;

	ret = NULL;
//	printf("%s\n", arg);
	puts("01");
	printf("%p\n", arg);
	while (*arg && (ft_iswhispa(*arg) || *arg == '|' || *arg == ','))
		++arg;
	puts("02");
	if (*arg == ';' || !*arg)
		return (ret);
	puts("03");
	if (*arg == '"')
	{
		puts("04");
		ret = lx_pa_argstr(&arg);
		ret->next = lx_pa_firstrule(arg);
	}
/*	else if (spe[2] == 1)
			lx_pa_argexp(&tmp, &(*spe), &ret);
	else
		lx_pa_argrul(&tmp, &(*spe), &ret, cur->key);
*/	return (ret);
}

t_lx_rule		*lx_pa_translate(t_lx_line *line)
{
	t_lx_line	*cur;
	t_lx_rule	*ret;
	t_lx_rule	*tmp;

	tmp = ret = malloc(sizeof(t_lx_rule));
	cur = line;
	while (cur)
	{
//		printf("key = %c  arg = %c    %p\n", *(cur->key), (cur->arg)[1], cur);
//		printf("%p  %s\n", cur, cur->key);
		puts("00001");
		tmp->first = lx_pa_firstrule(cur->arg);
		puts("00002");
		tmp->next = NULL;
		puts("00003");
		cur = cur->next;
		puts("00004");
		if (cur)
			tmp = tmp->next = malloc(sizeof(t_lx_rule));
		puts("00005");
	}
	puts("ici");
/*	tmp = ret;
	tmp->first = lx_pa_firstrule();
	while ((tmp = tmp->next))
		tmp->first = lx_pa_firstrule(line, ++i);
	allfree(3, line->key, line->arg, line);
	while ((line = line->next))
		allfree(3, line->key, line->arg, line);
*/	return (ret);
}
