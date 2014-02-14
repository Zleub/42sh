/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 00:27:13 by adebray           #+#    #+#             */
/*   Updated: 2014/01/12 18:20:22 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			_size;
	size_t			len;
	char			*_dst;
	const char		*_src;

	_size = size;
	_dst = dst;
	_src = src;
	while (*_dst != '\0' && _size-- != 0)
		_dst++;
	len = _dst - dst;
	_size = size - len;
	if (_size == 0)
		return (len + ft_strlen((char *)_src));
	while (*_src != '\0')
	{
		if (_size != 1)
		{
			*_dst++ = *_src;
			_size--;
		}
		_src++;
	}
	*_dst = '\0';
	return (len + (_src - src));
}
