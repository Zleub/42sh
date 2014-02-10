/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 19:41:34 by adebray           #+#    #+#             */
/*   Updated: 2014/02/03 19:49:20 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh3.h>

t_tree				*create_node(void)
{
	t_tree			*tree;

	tree = (t_tree *)malloc(sizeof(t_tree));
	tree->type = -1;
	tree->status = -1;
	tree->str = NULL;
	tree->leaf = NULL;
	tree->next = NULL;
	return (tree);
}
