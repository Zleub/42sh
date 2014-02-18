/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 05:22:02 by nsierra-          #+#    #+#             */
/*   Updated: 2014/02/18 05:23:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errors.h"
#include "42sh.h"
#include "env.h"
#include <stdlib.h>
#include <stdio.h>

static void			suppress(char **env, char **new_env, char **args)
{
	int				i;
	int				j;
	int				k;
	int				must_cpy;

	i = j = k = 0;
	while (env[i] != NULL)
	{
		must_cpy = 1;
		k = 0;
		while (args[k] != NULL)
		{
			if (!ft_strncmp(args[k], env[i], ft_strlen(args[k]))
				&& env[i][ft_strlen(args[k])] == '=')
			{
				args[k][0] = '\t';
				must_cpy = 0;
				break ;
			}
			++k;
		}
		if (must_cpy == 1)
			new_env[j++] = ft_strdup(env[i]);
		++i;
	}
}

static int			valid_input_or_die(const char **args)
{
	size_t			args_size;

	if (!args)
		return (ft_print(ERROR(UNSETENV, E_GENERIC), 2, 0));
	args_size = env_get_size(args);
	if (args_size == 1)
		return (ft_print(ERROR(UNSETENV, E_NOT_ENOUGH_ARG), 2, 0));
	else if (args_size == 0)
		return (ft_print(ERROR(UNSETENV, E_GENERIC), 2, 0));
	else
		return (1);
}

int					builtin_unsetenv(t_env *e, char **args)
{
	int				new_env_size;
	int				i;
	char			**new_env;

	i = 1;
	new_env_size = 0;
	if (!valid_input_or_die((const char **)args))
		return (0);
	while (args[i] != NULL)
	{
		if (env_is_set((const char **)e->env, args[i]) >= 0)
			++new_env_size;
		++i;
	}
	new_env_size = env_get_size((const char **)e->env) - new_env_size;
	if (!(new_env = NULL)
		&& !(new_env = malloc(sizeof(char *) * new_env_size + 1)))
		return (ft_print(ERROR(UNSETENV, E_GENERIC), 2, 0));
	new_env[new_env_size] = NULL;
	suppress(e->env, new_env, args + 1);
	env_destroy(e->env);
	e->env = new_env;
	return (1);
}
