/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 06:59:55 by nsierra-          #+#    #+#             */
/*   Updated: 2014/02/01 06:59:57 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t				st_strlen(const char *str)
{
	const char				*keep;

	keep = str;
	while (*str != '\0')
		++str;
	return (str - keep);
}

char						*ft_strdup(const char *str)
{
	int						len;
	char					*new_str;
	char					*keep;

	new_str = NULL;
	len = st_strlen(str);
	if (!(new_str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	keep = new_str;
	while (*str != '\0')
	{
		*new_str = *str;
		++str;
		++new_str;
	}
	*new_str = '\0';
	return (keep);
}
