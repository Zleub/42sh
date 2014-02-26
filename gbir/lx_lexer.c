/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 15:10:31 by gbir              #+#    #+#             */
/*   Updated: 2014/02/26 07:38:33 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "lexer.h"
#include "libft.h"

void			lx_lexer(t_lx_rule *first)
{
	t_lx_arg	*cur;
	while (first)
	{
		cur = first->first;
		while (cur)
		{
			printf("RULE: [%s] [%s] [%d] [%d]\n", cur->s1, cur->s2, cur->rule, cur->type);
			cur = cur->next;
		}
		first = first->next;
	}
}
