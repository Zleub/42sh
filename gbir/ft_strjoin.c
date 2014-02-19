/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 17:13:08 by gbir              #+#    #+#             */
/*   Updated: 2014/01/22 19:40:35 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	char	*cur;
	int		n;

	if (s1 && s2)
	{
		n = ft_strlen(s1) + ft_strlen(s2);
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
