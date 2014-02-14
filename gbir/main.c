/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:19:38 by gbir              #+#    #+#             */
/*   Updated: 2014/02/14 19:22:03 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "gnl.h"
#include "libft.h"
#include <fcntl.h>

void	lx_lexer()
{

}

void	lx_pars_lexerfile(char *cur)
{
	static char	*line = NULL;
	char		*tmp;
	int			iscmd;

	tmp = (line) ? line : cur;
	iscmd = 0;
	while (*tmp)
	{
		if (iscmd && *tmp == ' ' && *(tmp + 1) == ';')
		{
			ft_putendl((line) ? line : cur);//new cmd
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

int		main(void)
{
	char	*tmp;
	int		fd;

	fd = open("lexer.gmr", O_RDONLY);
	while (get_next_line(fd, &tmp) > 0)
		lx_pars_lexerfile(tmp);
	return (0);
}
