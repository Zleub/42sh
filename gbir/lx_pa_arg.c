/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_pa_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 20:28:32 by gbir              #+#    #+#             */
/*   Updated: 2014/02/17 23:36:10 by gbir             ###   ########.fr       */
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
	ret->rule = NULL;
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
	len = *tmp;
	while (*len && *len != '"')
		++len;
	if (!(*len))
		exit(0);//error: incorect args
	cur->s1 = malloc(sizeof(char) * ((len - *tmp) + 1));
	cur->s1 = ft_strncpy(cur->s1, *tmp, len - *tmp);
	*tmp = len + 1;
	cur->type = 1;
	return (ret);
}
/*
t_lx_arg		*lx_pa_argexp(char **tmp)
{
}

t_lx_arg		*lx_pa_argrule(char **tmp, char *key)
{
}
*/
