/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 17:27:11 by adebray           #+#    #+#             */
/*   Updated: 2014/02/06 22:30:30 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH3_H
# define SH3_H

#include <libft.h>
#include <gnl.h>
#include <ft_printf.h>

#include <stdlib.h>
#include <term.h>

typedef struct		s_gnl
{
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

enum				e_tree_type
{
	NODE, LEAF
}					;

enum				e_tree_status
{
	ONCE, LOOP, LIST, CAT, MIX
}					;

typedef struct		s_tree
{
	char			type;
	char			status;
	char			*str;
	struct s_tree	*leaf;
	struct s_tree	*next;
}					t_tree;

t_tree				*create_node(void);

#endif
