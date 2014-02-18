/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 03:59:45 by gbir              #+#    #+#             */
/*   Updated: 2014/02/02 04:09:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int		st_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		++s;
	return (s - str);
}

int				ft_print(const char *str, int fd, int ret)
{
	write(fd, str, st_strlen(str));
	return (ret);
}
