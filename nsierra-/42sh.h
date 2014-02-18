#ifndef SH_H
# define SH_H

typedef struct		s_env
{
	int				uid;
	char			**env;
	char			*path;
	char			*cwd;
	char			*owd;
	char			*home;
}					t_env;

/*
** CAUTION ! CAUTION ! CAUTION ! CAUTION !
** Needs to be discussed.
**
** Inside the args of every builtin funciton, will there be at first (args[0])
** the name of the command ?
** If not, it's important to update ALL implementations (mosty on error
** checking and such).
**
** All functions here as implemented here must recieve at least one 
** dimention of args array,
** i.e. for input "setenv HELLO world", the builtin_setenv() function will
** recieve :
** args[0] = "setenv"
** args[1] = "HELLO"
** args[2] = "world"
** args[3] = NULL
**
** Thank you for your time, and have a shower. Thank you again.
*/

/*
** Takes (at most) two arguments, which will respectively be the name and the
** value of a new variable set into env. If no argument is given, prints the
** current env. Returns 0 in case of failure, and 1 on success.
*/
int					builtin_setenv(t_env *e, char **args);
/*
** Takes n arguments and deletes any argument corresponding to an env var.
** Returns 0 on failure, 1 on success.
*/
int					builtin_unsetenv(t_env *e, char **args);
int					builtin_cd(t_env *e, char **args);
int					builtin_env(t_env *e, char **args);
int					builtin_echo(t_env *e, char **args);
int					builtin_exit(t_env *e, char **args);

int					ft_print(const char *str, int fd, int ret);
#endif /* !SH_H */
