/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:30:29 by nsierra-          #+#    #+#             */
/*   Updated: 2014/02/14 10:31:34 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include <stddef.h>

/*
** Specify a size and returns a char ** filled with NULL of size + 1.
** Returns NULL on failure.
*/
char			**env_create_new(size_t size);
/*
** Copies src into dst. If dst is NULL, then it will be malloc'd. Otherwise,
** make sure dst is big enough. Returns NULL on failure.
*/
char			**env_copy(const char **src, char **dst);
/*
** Looks for the variable ID specified by var (case-sensitive). Returns var
** index if var is found. Otherwise, it returns -1.
*/
int				env_is_set(const char **env, const char *var);
/*
** Returns the size of the NULL-terminated array pointed by env.
*/
size_t			env_get_size(const char **env);
/*
** Creates a new env, copies the old one into it and adds the couple var + val
** at the end of the array. On successfull, returns a pointer to the new env
** and frees the old one. Returns NULL on failure and does not free the old
** env.
*/
char			**env_add_var(char **env, const char *var, const char *value);
/*
** Looks for the index of the variable specified by var into env. On
** successfull, frees the old variable, sets a new couple var + val at
** this very index and returns the index.
** Returns -1 on failure.
*/
int				env_update_var(char **env, const char *var, const char *value);
void			env_destroy(char **env);
void			env_print(const char **env);

#endif /* !ENV_H */
