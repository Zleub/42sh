/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 07:38:25 by nsierra-          #+#    #+#             */
/*   Updated: 2014/01/03 07:38:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && s2 != '\0' && *s1 == *s2 && n)
	{
		if (*s1 == '\0')
			return (0);
		--n;
		++s1;
		++s2;
	}
	if (n == 0)
		return (0);
	if (*s1 > *s2)
		return (1);
	else if (*s1 < *s2)
		return (-1);
	else
		return (0);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && s2 != '\0' && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	if (*s1 > *s2)
		return (1);
	else if (*s1 < *s2)
		return (-1);
	else
		return (0);
}
