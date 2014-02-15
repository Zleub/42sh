/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:28:59 by nsierra-          #+#    #+#             */
/*   Updated: 2014/02/14 10:29:59 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** BEWARE !
** This file is not meant to be included in the project. It's there for testing
** purposes only. Therefore you'll find some of the horrific functions from
** libc we're not allowed to use, such as printf() (yeak), strdup() and fml().
*/

#define TEST_UPDATE
/*#define TEST_ADD*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "env.h"

static char				**get_env(void)
{
	extern char			**environ;
	char				**new_env;
	int					i;

	i = 0;
	while (environ[i] != NULL)
		++i;
	if (!(new_env = NULL) && !(new_env = malloc(sizeof(char *) * i + 1)))
		return (NULL);
	new_env[i] = NULL;
	i = 0;
	while (environ[i] != NULL)
	{
		new_env[i] = strdup(environ[i]);
		++i;
	}
	return (new_env);
}

static void				print_env(const char **env)
{
	while (*env)
		printf("%s\n", *env++);
}

static void				pause_loop(void)
{
	while (42)
		;
}

/* char			**env_add_var(char **env, const char *var, const char *value) */

int						main(void)
{
	char				**env;

	env = get_env();

#ifdef TEST_UPDATE
	if (env_update_var(NULL, "LESS", NULL) < 0)
		puts("Error you bitch.");
	else
		print_env((const char **)env);
#endif /* !TEST_UPDATE */

#ifdef TEST_ADD
	if (!env_add_var(env, ))
#endif /* !TEST_ADD */
	pause_loop();
	return (EXIT_SUCCESS);
}
