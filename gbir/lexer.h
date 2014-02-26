/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:25:40 by gbir              #+#    #+#             */
/*   Updated: 2014/02/26 07:34:35 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stdio.h> //supr

typedef struct	s_lx_rule t_lx_rule;
typedef struct	s_lx_arg t_lx_arg;

/*
** Struct for general args
** type
**  1  = "string"
**  2  = [expression]
**  3  = rule
**  4  = {rule}			(loop)
*/
struct			s_lx_arg
{
	char		*s1;
	char		*s2;
	int			rule;
	int			type;
	t_lx_arg	*next;
};

/*
** first arg and link of the last line
*/
struct			s_lx_rule
{
	t_lx_arg	*first;
	t_lx_rule	*next;
};

/*
** save a link of args and key of all line
*/
typedef struct			s_lx_line
{
	char				*key;
	char				*arg;
	struct s_lx_line	*next;
}						t_lx_line;

t_lx_rule	*lx_pars_lexerfile(char *cur);
char		*lx_supr_line(char *line);
t_lx_rule	*lx_pa_translate(t_lx_line *line);
int			lx_pa_isspe(int *spe, char c);
t_lx_arg	*lx_pa_argstr(char **tmp);
t_lx_arg	*lx_pa_argexp(char **tmp);
t_lx_arg	*lx_pa_argrule(char **tmp, t_lx_line *line);
void		lx_lexer(t_lx_rule *first);

#endif
