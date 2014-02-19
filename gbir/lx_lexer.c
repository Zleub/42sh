/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 15:10:31 by gbir              #+#    #+#             */
/*   Updated: 2014/02/15 15:32:59 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "lexer.h"
#include "libft.h"
/*
void			lx_lexer(char *line, t_lx_rul *first, t_lx_key *key)
{

}

void			lx_pars_lexerfile(char *file)
{
	static char	*line = NULL;
	char		*tmp;
	int			iscmd;

	(void)first;
	tmp = (line) ? line : cur;
	iscmd = 0;
	while (*tmp)
	{
		if (iscmd && *tmp == ' ' && *(tmp + 1) == ';')
		{
//			ft_putendl((line) ? line : cur);//new cmd
			lx_lexer((line) ? line : cur, first, key);
			free(cur);
			if (line)
				free(line);
			line = NULL;
			return ;
		}
		else if (*tmp == '=')
			iscmd = 1;
		++tmp;
	}
	if ((tmp = line) && (line = ft_strjoin(line, cur)))
		allfree(2, cur, tmp);
	else
		line = cur;
}
*/
