/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 19:41:34 by adebray           #+#    #+#             */
/*   Updated: 2014/02/14 09:48:32 by adebray          ###   ########.fr       */
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

t_treebag			*create_bag(void)
{
	t_treebag		*bag;

	bag = (t_treebag*)malloc(sizeof(t_treebag));
	bag->tree = create_node();
	bag->tree_head = bag->tree;
	return (bag);
}
