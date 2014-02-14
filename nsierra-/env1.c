/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:01:06 by nsierra-          #+#    #+#             */
/*   Updated: 2014/02/14 11:28:13 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char			**env_create_new(size_t size)
{
	char		**new_env;

	if (!(new_env = NULL) && !(new_env = malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (size != 0)
	{
		new_env[size] = NULL;
		--size;
	}
	return (new_env);
}

size_t			env_get_size(const char **env)
{
	size_t		size;

	size = 0;
	if (env)
	{
		while (env[size] != NULL)
			++size;	
	}
	return (size);
}

char			**env_copy(const char **src, char **dst)
{
	static int	i = 0;

	if (!dst && ++i == 1)
		env_copy(src, env_create_new(env_get_size(src)));
	else if (!dst && !(i = 0))
		return (NULL);
	i = 0;
	while (src[i] != NULL)
	{
		if (!(dst[i] = ft_strdup(src[i])))
		{
			while (i >= 0)
			{
				if (dst[i])
					free(dst[i]);
				--i;
			}
			i = 0;
			return (NULL);
		}
		++i;
	}
	i = 0;
	return (dst);
}

int				env_is_set(const char **env, const char *var)
{
	int			i;

	i = 0;
	while (env[i] != NULL)
	{
		if (!ft_strncmp(var, env[i], ft_strlen(var)))
			return (i);
		++i;
	}
	return (-1);
}

void			env_destroy(char **env)
{
	int			i;

	i = 0;
	while (env[i] != NULL)
		free(env[i++]);
	free(env);
}
