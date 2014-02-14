/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:27:13 by adebray           #+#    #+#             */
/*   Updated: 2013/12/29 15:53:55 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		tmp;

	i = 0;
	tmp = n;
	while (s2[i] != '\0' && i < n)
	{
		s1[i] = s2[i];
		i = i + 1;
	}
	while (i < n)
	{
		s1[i] = '\0';
		i = i + 1;
	}
	return (s1);
}
