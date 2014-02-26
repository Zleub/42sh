/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_pa_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 20:28:32 by gbir              #+#    #+#             */
/*   Updated: 2014/02/26 07:59:07 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <stdlib.h>

static t_lx_arg	*lx_pa_newarg(void)
{
	t_lx_arg	*ret;

	ret = malloc(sizeof(t_lx_arg));
	ret->s1 = NULL;
	ret->s2 = NULL;
	ret->rule = -1;
	ret->type = 0;
	ret->next = NULL;
	return (ret);
}

t_lx_arg		*lx_pa_argstr(char **tmp)
{
	t_lx_arg	*ret;
	t_lx_arg	*cur;
	char		*len;

	cur = ret = lx_pa_newarg();
	len = *tmp + 1;
//	puts("ici  ici");
	while (*len && *len != '"')
		++len;
//	printf("len = %ld", len - *tmp);
	if (!(*len))
		exit(0);//error: incorect args
	cur->s1 = malloc(sizeof(char) * (len - *tmp));
	cur->s1 = ft_strncpy(cur->s1, *tmp + 1, len - *tmp - 1);
//	printf("    STRI: [%s]\n", cur->s1);
	*tmp = len + 1;
	cur->type = 1;
	return (ret);
}

t_lx_arg		*lx_pa_argexp(char **tmp)
{
	t_lx_arg	*cur;

	cur = lx_pa_newarg();
	cur->type = 2;
	cur->s1 = malloc(sizeof(char));
	*(cur->s1) = **tmp;
//	cu_tmp = *tmp + 1;
	cur->s2 = malloc(sizeof(char));
	*(cur->s2) = *(*tmp + 2);
//	printf("    EXPR: tmp = %.3s  |%c| |%c|\n", *tmp, **tmp, *(*tmp + 2));
	*tmp += 2;
//	if (*(*tmp + 1) != ']')
//		;
	return (cur);
}

t_lx_arg		*lx_pa_argrule(char **tmp, t_lx_line *line)
{
	t_lx_arg	*cur;
	char		*li_tmp;
	char		*cu_tmp;
	int			i;

	i = 0;
	cur = lx_pa_newarg();
	cur->type = (**tmp == '{' && ++(*tmp)) ? 4 : 3;
	while (42)
	{
		cu_tmp = *tmp;
		li_tmp = line->key;
//		printf("    RULE: %.6s %.6s\n", cu_tmp, li_tmp);
		while (!ft_iswhispa(*cu_tmp) && *cu_tmp != '}' && *cu_tmp != ',')
		{
//			printf("%c\n", *cu_tmp);
			if (*cu_tmp++ != *li_tmp++)
				break ;
		}
		if ((ft_iswhispa(*cu_tmp) || *cu_tmp == '}' || *cu_tmp == ',') &&
			(ft_iswhispa(*li_tmp) || *li_tmp == '='))
		{
			cur->rule = i;
			break ;
		}
		line = line->next;
		++i;
	}
	if (cu_tmp == *tmp)
		exit(0);//error incorect rule
	*tmp = (cur->type == 4) ? cu_tmp + 1 : cu_tmp;
	return (cur);
}
