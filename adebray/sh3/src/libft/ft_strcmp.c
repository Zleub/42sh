/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:27:13 by adebray           #+#    #+#             */
/*   Updated: 2014/02/10 15:05:59 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	lenght;

	lenght = ft_strlen(s2);
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (*s2);
	else if (!s2)
		return (*s1);
	while (*s1 == *s2)
	{
		if (lenght-- == 0)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
