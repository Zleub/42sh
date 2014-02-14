/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 17:27:11 by adebray           #+#    #+#             */
/*   Updated: 2014/02/14 10:08:08 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH3_H
# define SH3_H

#include <libft.h>
#include <gnl.h>
#include <ft_printf.h>

#include <stdlib.h>
#include <term.h>

enum				e_tree_type
{
	NODE, LEAF
}					;

enum				e_tree_status
{
	ONCE, LOOP, LIST, CAT, MIX
}					;

typedef struct		s_node_model
{
	char					type;
	char					status;
	char					*str;
	struct s_node_model		*leaf;
	struct s_node_model		*next;
}							t_tree;

typedef struct		s_ope
{
	char			equals;
	char			dquote;
	char			crush;
}					t_ope;

typedef struct		s_tree_bag
{
	t_tree			*tree;
	t_tree			*tree_head;
}					t_treebag;

t_tree				*create_node(void);
t_treebag			*create_bag(void);
void				print_tree(t_tree *tree, int i);

#endif
