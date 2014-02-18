#include <stdlib.h>
#include "libft.h"
#include "errors.h"
#include "env.h"
#include "42sh.h"

/*
** This function deals with error input.
** Important point : due to the implementation, the case where "setenv"
** is called for printing the environnement is managed here (where
** arg_size is equal to one (i.e. no argument is given))
*/
static int			valid_input_or_die(t_env *e, const char **args)
{
	size_t			args_size;

	args_size = env_get_size(args);
	if (args_size > 3)
		return (ft_print(ERROR(SETENV, E_TOO_MANY_ARG), 2, 0));
	else if (args_size == 0)
		return (ft_print(ERROR(SETENV, E_INPUT), 2, 0));
	else if (args_size == 1)
	{
		env_print((const char **)e->env);
		return (0);
	}
	else
		return (1);
}

int					builtin_setenv(t_env *e, char **args)
{
	if (!valid_input_or_die(e, (const char **)args))
		return (0);
	if (env_is_set((const char **)e->env, (const char *)args[1]) < 0)
	{
		if (!(e->env = env_add_var(e->env, args[1], args[2])))
			return (ft_print(ERROR(SETENV, E_GENERIC), 2, 0));
		return (1);		
	}
	else if (env_update_var(e->env, args[1], args[2]) < 0)
		return (ft_print(ERROR(SETENV, E_GENERIC), 2, 0));
	if (!ft_strcmp("PATH", args[1]))
	{
		if (e->path)
			free(e->path);
		if (!(e->path = ft_strdup(args[2])))
			e->path = NULL;
	}
	return (1);
}
