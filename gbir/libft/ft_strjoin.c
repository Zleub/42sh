/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:13:08 by gbir              #+#    #+#             */
/*   Updated: 2014/02/15 14:56:06 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	st_strlen(const char *s)
{
	char	*save;

	save = (char*)s;
	while (*save != '\0')
		++save;
	return (save - s);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	char	*cur;
	int		n;

	if (s1 && s2)
	{
		n = st_strlen(s1) + st_strlen(s2);
		s = (char*)malloc(sizeof(char) * (n + 1));
		cur = s;
		if (s != NULL)
		{
			while (*s1 && n--)
				*cur++ = *s1++;
			while (*s2 && n--)
				*cur++ = *s2++;
			*cur = '\0';
			return (s);
		}
	}
	return (0);
}
