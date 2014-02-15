/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_old.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 11:12:01 by adebray           #+#    #+#             */
/*   Updated: 2014/02/15 00:02:12 by adebray          ###   ########.fr       */
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

int				get_leaf(t_ope *ope, t_tree *tree, char *str, int i)
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

t_tree		*treecmp(t_treebag *bag)
{
	t_tree		*tmp;


	tmp = bag->tree_head;
	while (tmp)
	{
		if (!ft_strcmp(tmp->str, bag->tree->leaf->str))
			return (tmp->leaf);
		tmp = tmp->next;
	}
	return (NULL);
}

int			get_node(t_ope *ope, t_treebag *bag, char *str, int i)
{
	char		buf[4096];
	int			j;

	j = 0;
	ft_strclr(buf);
	while (ft_isalpha(str[i]))
	{
		buf[j] = str[i];
		j += 1;
		i += 1;
	}
	bag->tree->leaf->str = ft_strndup(buf, j);
	bag->tree->leaf->type = NODE;
	if (ope->crush == 1)
		bag->tree->leaf->status = LOOP;
	else
		bag->tree->leaf->status = ONCE;
	bag->tree->leaf->leaf = treecmp(bag);
	return (i);
}

void			function_to_create_leaf_child_node(t_treebag *bag, char *str)
{
	int		i;
	t_ope	*ope;
	t_tree	*leaf_head;

	ope = (t_ope *)malloc(sizeof(t_ope));
	ope->dquote = ope->equals = ope->crush = 0;
	leaf_head = NULL;
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
			if (!bag->tree->leaf)
			{
				bag->tree->leaf = create_node();
				leaf_head = bag->tree->leaf;
			}
			i = get_leaf(ope, bag->tree, str, i);
			bag->tree->leaf->next = create_node();
			bag->tree->leaf = bag->tree->leaf->next;
		}
		else if (ft_isalpha(str[i]) && ope->equals == 1) /* IF NODE */
		{
			if (!bag->tree->leaf)
			{
				bag->tree->leaf = create_node();
				leaf_head = bag->tree->leaf;
			}
			i = get_node(ope, bag, str, i);
			bag->tree->leaf->next = create_node();
			bag->tree->leaf = bag->tree->leaf->next;
		}
		else if (str[i] == '|' && ope->equals == 1)
		{
			if (bag->tree->status == CAT)
				bag->tree->status = MIX;
			else if (bag->tree->status != MIX)
				bag->tree->status = LIST;
		}
		else if (str[i] == ',' && ope->equals == 1)
		{
			if (bag->tree->status == LIST)
				bag->tree->status = MIX;
			else if (bag->tree->status != MIX)
				bag->tree->status = CAT;
		}
		i += 1;
	}
	bag->tree->leaf = leaf_head;
}

t_tree		*make_node(t_treebag *bag, char *tmp)
{
	int		i;

	bag->tree->type = bag->tree->status = i = 0;
	while (ft_isalpha(tmp[i]))
		i += 1;
	bag->tree->str = ft_strndup(tmp, i);
	bag->tree->leaf = NULL;
	function_to_create_leaf_child_node(bag, tmp);
	if (ft_strncmp(tmp, "grammar", 7))
	{
		bag->tree->next = create_node();
		bag->tree = bag->tree->next;
	}
	return (bag->tree);
}

t_tree		*fd_to_tree(int fd)
{
	int		i;
	char	*tmp;
	t_treebag	*bag;

	bag = create_bag();
	while (get_next_line(fd, &tmp) > 0)
	{
		if (tmp[0] != '\t')
			bag->tree = make_node(bag, tmp);
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
	return (bag->tree);
}

int			main(void)
{
	int		fd;

	if ((fd = open("test.gmr", O_RDONLY)) < 0)
		return (-1);
	print_tree(fd_to_tree(fd), 0);
	return (0);
}
