/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 13:54:26 by Arno              #+#    #+#             */
/*   Updated: 2014/02/11 13:56:38 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh3.h>

static void		print_tree_adress(t_tree *tree, int i)
{
	while (i--)
		ft_printf("\t");
	ft_printf("\e[38;5;%umtree : <%p>\n", (unsigned int)tree % 255 + 1, tree);
	ft_printf("\e[39m");
}

static void		print_tree_str(t_tree *tree, int i)
{
	while (i--)
		ft_printf("\t");
	ft_printf("* tree->str : '%s'\n", tree->str);
}

static void		print_tree_type(t_tree *tree, int i)
{
	while (i--)
		ft_printf("\t");
	if (tree->type == NODE)
		ft_printf("NODE ");
	else if (tree->type == LEAF)
		ft_printf("\tLEAF ");
	else
		ft_printf("\n");
}

static void		print_tree_status(t_tree *tree)
{
	if (tree->status == ONCE)
		ft_printf("ONCE\n");
	else if (tree->status == LOOP)
		ft_printf("LOOP\n");
	else if (tree->status == LIST)
		ft_printf("LIST\n");
	else if (tree->status == CAT)
		ft_printf("CAT\n");
	else if (tree->status == MIX)
		ft_printf("MIX\n");
	else
		ft_printf("\n");
}

void			print_tree(t_tree *tree, int i)
{
	print_tree_adress(tree, i);
	print_tree_str(tree, i);
	print_tree_type(tree, i);
	print_tree_status(tree);
	if (tree->leaf)
		print_tree(tree->leaf, i + 1);
	if (tree->next)
		print_tree(tree->next, i);
}