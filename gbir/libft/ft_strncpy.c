/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:27:13 by adebray           #+#    #+#             */
/*   Updated: 2014/02/17 20:24:08 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*tmp;
	char	*ret;

	tmp = (char*)s2;
	ret = s1;
	while (*tmp != '\0' && (size_t)(s1 - ret) < n)
		*s1++ = *tmp++;
	while ((size_t)(s1 - ret) < n + 1)
		*s1++ = '\0';
	return (ret);
}
