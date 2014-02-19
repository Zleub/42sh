/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_pars_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 12:36:58 by gbir              #+#    #+#             */
/*   Updated: 2014/02/17 17:14:48 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lexer.h"
#include <stdlib.h>

char		*lx_supr_line(char *line)
{
	char	*ret;
	char	*tmp;
	char	*fre;
	int		lvl;

	lvl = 0;
	fre = line;
	tmp = ret = malloc(sizeof(char) * (ft_strlen(line) + 1));
	while (*line)
	{
		if (lvl == 1 && *line == '#' && (lvl = 2)  && (++line))
			continue ;
		else if (lvl == 1 && ft_iswhispa(*line) && (++line))
			continue ;
		else if (lvl == 2 && *line != '\n'  && (++line))
			continue ;
		if (*line != '\n')
		{
			*tmp = *line;
			++tmp;
			lvl = 0;
		}
		else
			lvl = 1;
		++line;
	}
	*tmp = 0;
	free(fre);
	return (ret);
}
