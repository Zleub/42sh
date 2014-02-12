/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 11:12:01 by adebray           #+#    #+#             */
/*   Updated: 2014/02/11 23:32:55 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh3.h>

/*
** OPEN NECECITY
*/
#include <fcntl.h>

int							tswitch(int i)
{
	struct termios			term;
	static struct termios	save;

	if (i == 1)
	{
		if (tgetent(0, getenv("TERM")) < 1)
			return (-1);
		tcgetattr(0, &term);
		save = term;
		term.c_lflag &= ~ICANON;
		term.c_lflag &= ~ECHO;
		tcsetattr(0, 0, &term);
		return (0);
	}
	else
	{
		tcsetattr(0, 0, &save);
		return (0);
	}
}

char	*ft_strndup(const char *s1, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dup == NULL)
		return (NULL);
	else
	{
		while (n-- && s1[i] != '\0')
		{
			dup[i] = s1[i];
			i = i + 1;
		}
		dup[i] = '\0';
		return (dup);
	}
}

int				get_node(t_ope *ope, t_tree *tree, char *str, int i)
{
	char		buf[4096];
	int			j;

	i += 1;
	j = 0;
	ft_strclr(buf);
	while (ope->dquote)
	{
		buf[j] = str[i];
		if (str[i] == '"')
			ope->dquote = 0;
		j += 1;
		i += 1;
	}
	tree->leaf->str = ft_strndup(buf, j - 1);
	tree->leaf->type = LEAF;
	if (ope->crush == 1)
		tree->leaf->status = LOOP;
	else
		tree->leaf->status = ONCE;
	return (i);
}

void			function_to_create_leaf_child_node(t_tree *tree, t_tree *tree_head, char *str)
{
	int		i;
	int		j;
	t_ope	*ope;
	t_tree	*leaf_head;
	char		buf[4096];
	t_tree	*tmp = tree_head;

	ope = (t_ope *)malloc(sizeof(t_ope));
	ope->dquote = ope->equals = ope->crush = 0;
	leaf_head = NULL;
	if (!tree->leaf) /* IF ACTUAL NODE (tree) DOES NOT HAVE LEAFS */
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '=')
				ope->equals = 1;
			else if (str[i] == '{')
				ope->crush = 1;
			else if (str[i] == '}')
				ope->crush = 0;
			else if (str[i] == '"' && ope->equals == 1) /* IF "LEAF" */
			{
				ope->dquote = 1;
				if (!tree->leaf)
				{
					tree->leaf = create_node();
					leaf_head = tree->leaf;
				}

				i = get_node(ope, tree, str, i);
				// i += 1;
				// j = 0;
				// ft_strclr(buf);
				// while (ope->dquote)
				// {
				// 	buf[j] = str[i];
				// 	if (str[i] == '"')
				// 		ope->dquote = 0;
				// 	j += 1;
				// 	i += 1;
				// }
				// tree->leaf->str = ft_strndup(buf, j - 1);
				// tree->leaf->type = LEAF;
				// if (ope->crush == 1)
				// 	tree->leaf->status = LOOP;
				// else
				// 	tree->leaf->status = ONCE;
				tree->leaf->next = create_node();
				tree->leaf = tree->leaf->next;
			}
			else if (ft_isalpha(str[i]) && ope->equals == 1) /* IF NODE */
			{
				if (!tree->leaf)
				{
					tree->leaf = create_node();
					leaf_head = tree->leaf;
				}
				j = 0;
				ft_strclr(buf);
				while (ft_isalpha(str[i]))
				{
					buf[j] = str[i];
					j += 1;
					i += 1;
				}
				tree->leaf->str = ft_strndup(buf, j);
				tree->leaf->type = NODE;
				if (ope->crush == 1)
					tree->leaf->status = LOOP;
				else
					tree->leaf->status = ONCE;
				while (tmp)
				{
					if (!ft_strcmp(tmp->str, tree->leaf->str))
						tree->leaf->leaf = tmp->leaf;
					tmp = tmp->next;
				}
				tmp = tree_head;
				tree->leaf->next = create_node();
				tree->leaf = tree->leaf->next;
			}
			else if (str[i] == '|' && ope->equals == 1)
			{
				if (tree->status == CAT)
					tree->status = MIX;
				else if (tree->status != MIX)
					tree->status = LIST;
			}
			else if (str[i] == ',' && ope->equals == 1)
			{
				if (tree->status == LIST)
					tree->status = MIX;
				else if (tree->status != MIX)
					tree->status = CAT;
			}
			i += 1;
		}
		tree->leaf = leaf_head;
	}
}

t_tree		*make_node(t_tree *tree, t_tree *tree_head, char *tmp)
{
	int		i;

	tree->type = tree->status = i = 0;
	while (ft_isalpha(tmp[i]))
		i += 1;
	tree->str = ft_strndup(tmp, i);
	tree->leaf = NULL;
	function_to_create_leaf_child_node(tree, tree_head, tmp);
	if (ft_strncmp(tmp, "grammar", 7))
	{
		tree->next = create_node();
		tree = tree->next;
	}
	return (tree);
}

t_tree		*fd_to_tree(int fd)
{
	int		i;
	char	*tmp;
	t_tree	*tree;
	t_tree	*tree_head;

	tree = create_node();
	tree_head = tree;
	while (get_next_line(fd, &tmp) > 0)
	{
		if (tmp[0] != '\t')
			tree = make_node(tree, tree_head, tmp);
		else
		{
			i = 0;
			while (tmp[i] == '\t')
				i += 1;
			tmp = ft_strsub(tmp, i, ft_strlen(tmp) - i);
			ft_printf("tmp : %s\n", tmp);
		}
		free (tmp);
		tmp = NULL;
	}
	return (tree_head);
}

int			main(void)
{
	int		fd;

	if ((fd = open("test2.gmr", O_RDONLY)) < 0)
		return (-1);
	print_tree(fd_to_tree(fd), 0);
	return (0);
}

// int			main(void)
// {
// 	char un = 'a';
// 	char *deux = "Hello World";
// 	ft_printf("sizeof(un) = %d, sizeof(deux) = %d", sizeof(un), sizeof(deux));
// 	return (0);
// }
