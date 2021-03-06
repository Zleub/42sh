/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 00:23:43 by adebray           #+#    #+#             */
/*   Updated: 2013/12/29 15:53:37 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 && !s2)
		return (0);
	while (*s1 == *s2 && n > 1 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
		n = n - 1;
	}
	if (n > 0)
		return (int)(*s1 - *s2);
	return (0);
}
