/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:19:38 by gbir              #+#    #+#             */
/*   Updated: 2014/02/26 07:33:03 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //supr

int		main(void)
{
	char		tmp[1025];
	char		*file;
	int			fd;

	file = malloc(sizeof(char));
	*file = 0;
	fd = open("lexer.gmr", O_RDONLY);
	while (read(fd, &tmp, 1024) > 0)
		file = ft_strjoin(file, tmp);
	lx_lexer(lx_pars_lexerfile(file));
	return (0);
}
