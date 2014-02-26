/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 15:20:32 by gbir              #+#    #+#             */
/*   Updated: 2014/02/26 07:29:53 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "lexer.h"
#include "libft.h"
#include <stdlib.h>

/*
** spe[0] = Key, Arguments or new line
** spe[1] = out "" or in ""
** spe[2] = out [] or in []
** spe[3] = out {} or in {}
*/
int				lx_pa_isspe(int *spe, char c)
{
	if (spe[0] == 0 && c == '=' && (spe[0] = 1))
		return (1);
	if (spe[0] == 2 && c == ';' && !spe[1] && !spe[2] && !spe[3] && (spe[0] = 3))
		return (1);
	if (spe[1] == 0 && c == '"' && (spe[1] = 1))
		return (1);
	if (spe[1] && c == '"' && !(spe[1] = 0))
		return (1);
	if (spe[2] == 0 && c == '[' && (spe[2] = 1))
		return (1);
	if (spe[2] == 1 && c == ']' && !(spe[2] = 0))
		return (1);
	if (spe[3] == 0 && c == '{' && (spe[3] = 1))
		return (1);
	if (spe[3] == 1 && c == '}' && !(spe[3] = 0))
		return (1);
	return (0);
}

/*
** 
*/
static void		lx_pa_other(t_lx_line **cur, int *spe, char *tmp)
{
	if (spe[0] == 1)
	{
		(*cur)->arg = tmp;
//		printf("->%.8s\n", tmp);
		spe[0] = 2;
	}
	else if (spe[0] == 3)
	{
		while (ft_iswhispa(*tmp) || *tmp == ';')
		{
			++tmp;
			if (!*tmp)
			{
				free((*cur)->next);
				(*cur)->next = NULL;
				return ;
			}
		}
		(*cur) = (*cur)->next;
//		printf("=======  %.8s  %p\n", tmp, *cur);
		(*cur)->key = tmp;
		spe[0] = 0;
	}
}

t_lx_rule		*lx_pars_lexerfile(char *file)
{
	t_lx_line	*line;
	t_lx_line	*cur;
	char		*tmp;
	int			isspe[4] = {0};

	tmp = file = lx_supr_line(file);
	line = NULL;
	while (*tmp)
	{
		lx_pa_isspe(&(*isspe), *tmp);
		if (!line)
		{
//			printf("=======  %.8s\n", tmp);
			cur = line = malloc(sizeof(t_lx_line));
			line->key = malloc(sizeof(char));
			line->key = tmp;
			line->next = NULL;
		}
		else if (isspe[0] == 3)
			cur->next = malloc(sizeof(t_lx_line));
//		printf(" [%c] %d %d %d %d\n", *tmp, isspe[0], isspe[1], isspe[2], isspe[3]);
		lx_pa_other(&cur, &(*isspe), tmp);
		++tmp;
	}
	free(file);
//	printf("%p\n", line);
	return (lx_pa_translate(line));
}
