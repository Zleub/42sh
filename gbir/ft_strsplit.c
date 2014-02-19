/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 08:28:23 by gbir              #+#    #+#             */
/*   Updated: 2014/01/23 14:30:09 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nbrchar(char const *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == c && *(str - 1) != c)
			++i;
		++str;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*sa[2];
	char	**ret;
	char	**sr;
	int		i;

	i = ft_nbrchar(s, c);
	sa[0] = (char*)s - 1;
	ret = malloc(sizeof(char*) * (i + 2));
	sr = ret;
	ret[i + 1] = NULL;
	while (42)
	{
		if ((*s == c && (!*sr || (*s - 1) != c)) || *s == '\0')
		{
			if ((i = s - sa[0]) && (sa[1] = malloc(i)))
				*sr = sa[1];
			while (++sa[0] < s)
				*sa[1]++ = *sa[0];
			if (++sr && !(*sa[1] = '\0') && (sa[0] = (char*)s) && *s == '\0')
				break ;
		}
		++s;
	}
	return (ret);
}
