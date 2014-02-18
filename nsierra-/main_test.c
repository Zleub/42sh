/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:28:59 by nsierra-          #+#    #+#             */
/*   Updated: 2014/02/18 05:26:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** BEWARE !
** This file is not meant to be included in the project. It's there for testing
** purposes only. Therefore you'll find some of the horrific functions from
** libc we're not allowed to use, such as printf() (yeak), strdup() and fml().
**
**
** In order to test UNSETENV, you must strdup every single string in the array,
** because the function modifies the string passed as argument. If you don't
** strdup, it will result as a bus error, but it's normal.
*/

#define TEST_SETENV

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "42sh.h"
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
		new_env[i] = ft_strdup(environ[i]);
		++i;
	}
	return (new_env);
}

static void				pause_loop(void)
{
	while (42)
		;
}

int						main(void)
{
	t_env				e;
	char				*args_1[4] = {"setenv", "PATH", "/usr/bin", NULL};
	char				*args_2[4] = {"setenv", "CACA", "kokoooo", NULL};
	char				*args_3[5] = {NULL, NULL, NULL, NULL, NULL};

	e.env = get_env();
	e.path = NULL;
	builtin_setenv(&e, args_1);
	builtin_setenv(&e, args_2);
	env_print((const char **)e.env);
	puts("\n\n==========================================================\n\n");
	builtin_unsetenv(&e, args_3);
	env_print((const char **)e.env);
	env_destroy(e.env);
	pause_loop();
	return (EXIT_SUCCESS);
}
