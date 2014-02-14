/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:25:40 by gbir              #+#    #+#             */
/*   Updated: 2014/02/14 19:33:00 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/*
** Struct for regular expression
** exp: [expression]
*/
typedef struct		s_lx_exp
{
	char			first;
	char			last;
	struct s_lx_exp	next;
}					t_lx_exp;

/*
** Struct for string
** exp: "string"
*/
typedef struct		s_lx_str
{
	char			*str;
	struct s_lx_str	next;
}					t_lx_str;

#endif
