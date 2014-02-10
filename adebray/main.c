/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 11:12:01 by adebray           #+#    #+#             */
/*   Updated: 2014/02/10 15:31:37 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh3.h>

#include <fcntl.h>
#define TERMINALS "abcdefghijklmnopqrstuvwxyz"

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

void		is_lang(char *c)
{
	int		i;
	char	*lang;

	i = 0;
	lang = TERMINALS;
	while (lang[i])
	{
		if (*c == lang[i])
		{
			ft_printf("%c", *c);
		}
		i += 1;
	}
}

int			test(void)
{
	char	str[4] = {0};

	if(tswitch(1) == -1)
		return (-1);
	while (read(0, str, 4))
	{
		ft_printf("%d-%d-%d-%d\n", str[0], str[1], str[2], str[3]);
		// ft_striter(str, &is_lang);
		// ft_printf("\n");
		ft_strclr(str);
	}
	tswitch(0);
	return (0);
}

char		*ft_mstrcat(char *str_1, char *str_2)
{
	char	*ret;
	char	*p;

	ret = (char *)malloc(ft_strlen(str_1) + ft_strlen(str_2) + 1);
	p = ret;
	while (*str_1)
		*ret++ = *str_1++;
	while (*str_2)
		*ret++ = *str_2++;
	*ret = '\0';
	return (p);
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

unsigned int		ft_hashich(char *line)
{
	unsigned int	hashich;
	int				c;

	hashich = 5381;
	while ((c = *line++))
		hashich = ((hashich << 5) + hashich) ^ c;
	if (hashich > 256)
		return (hashich % 256);
	return (hashich);
}

void	print_tree(t_tree *tree, int i)
{
	int tmp;

	tmp = i;
	while (tmp--)
	{
		ft_printf("\t\e[38;5;%um", (unsigned int)tree % 255 + 1);
	}
		ft_printf("tree : <%p>\n", tree);

	ft_printf("\e[39m");
	tmp = i;
	while (tmp--)
		ft_printf("\t");
	ft_printf("* tree->str : '%s'\n", tree->str);
	tmp = i;
	while (tmp--)
		ft_printf("\t");
	// ft_printf("tree->type : '%d'", tree->type);
	if (tree->type == NODE)
		ft_printf(" - NODE ");
	else if (tree->type == LEAF)
		ft_printf(" - LEAF ");
	else
		ft_printf("\n");
	tmp = i;
	// while (tmp--)
		// ft_printf("\t");
	// ft_printf("tree->status : '%d'", tree->status);
	if (tree->status == ONCE)
		ft_printf(" - ONCE\n");
	else if (tree->status == LOOP)
		ft_printf(" - LOOP\n");
	else if (tree->status == LIST)
		ft_printf(" - LIST\n");
	else if (tree->status == CAT)
		ft_printf(" - CAT\n");
	else if (tree->status == MIX)
		ft_printf(" - MIX\n");
	else
		ft_printf("\n");




	if (tree->leaf)
		print_tree(tree->leaf, i + 1);

	if (tree->next)
		print_tree(tree->next, i);
}

void			function_to_create_leaf_child_node(t_tree *tree, t_tree *tree_head, char *str)
{
	char	equals;
	char	dquote;
	char	crush;
	int		i;
	int		j;
	char	buf[4096];
	t_tree	*leaf_head;

	t_tree	*tmp = tree_head;

	dquote = 0;
	equals = 0;
	crush = 0;
	leaf_head = NULL;
	if (!tree->leaf) /* IF ACTUAL NODE (tree) DOES NOT HAVE LEAFS */
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '=')
				equals = 1;
			else if (str[i] == '{')
				crush = 1;
			else if (str[i] == '}')
				crush = 1;
			else if (str[i] == '"' && equals == 1) /* IF "LEAF" */
			{
				dquote = 1;
				if (!tree->leaf)
				{
					tree->leaf = create_node();
					leaf_head = tree->leaf;
				}
				i += 1;
				j = 0;
				ft_strclr(buf);
				while (dquote)
				{
					buf[j] = str[i];
					if (str[i] == '"')
						dquote = 0;
					j += 1;
					i += 1;
				}
				tree->leaf->str = ft_strndup(buf, j - 1);
				tree->leaf->type = LEAF;
				if (crush == 1)
					tree->leaf->status = LOOP;
				else
					tree->leaf->status = ONCE;
				// ft_printf("1. -> tree leaf str = %s - %p\n", tree->leaf->str, tree->leaf);
				tree->leaf->next = create_node();
				tree->leaf = tree->leaf->next;

			}
			else if (ft_isalpha(str[i]) && equals == 1) /* IF NODE */
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
					if (str[i] == '"')
						dquote = 0;
					j += 1;
					i += 1;
				}
				tree->leaf->str = ft_strndup(buf, j);
				tree->leaf->type = NODE;
				if (crush == 1)
					tree->leaf->status = LOOP;
				else
					tree->leaf->status = ONCE;
				ft_printf("! ! ! ! DEGU DEBUG %p\n", tmp);
				while (tmp)
				{
					ft_printf("DEGU DEBUG %p\n", tmp);
					ft_printf("DEGU DEBUG tmp->str : %s VS %s : tree->leaf->str\n", tmp->str, tree->leaf->str);
					if (!ft_strcmp(tmp->str, tree->leaf->str))
					{
						ft_printf("SIGNAL\n");
						ft_printf("%p : %p\n", tree->leaf->leaf, tmp->leaf);
						/*** NOT WORKING BECAUSE OF STRCMP tree->leaf = tmp; */
						tree->leaf->leaf = tmp->leaf;
						// tree->leaf->type = tmp->type;
						// if (tree->leaf->status == LOOP)
						// 	ft_printf("HERE THE LOOP OF tree->leaf->str %s IS GONE\n", tree->leaf->str);
						// tree->leaf->status = tmp->status;
						// ft_printf("%p : %p\n", tree->leaf->leaf, tmp->leaf);
					}
					tmp = tmp->next;
				}
				tmp = tree_head;
				tree->leaf->next = create_node();
				tree->leaf = tree->leaf->next;
			}
			else if (str[i] == '|' && equals == 1)
			{
				if (tree->status == CAT)
					tree->status = MIX;
				else if (tree->status != MIX)
					tree->status = LIST;
			}
			else if (str[i] == ',' && equals == 1)
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

int			main(void)
{
	int		fd;
	int		i;
	int		start;
	char	*tmp;
	t_gnl	*head;
	t_gnl	*gnl;

	t_tree	*tree;
	t_tree	*tree_head;

	if ((fd = open("test2.gmr", O_RDONLY)) < 0)
		return (-1);

	start = 1;
	gnl = (t_gnl*)malloc(sizeof(t_gnl));
	head = gnl;
	tree = create_node();
	tree_head = tree;
	while (get_next_line(fd, &tmp) > 0)
	{
		if (tmp[0] != '\t') /* Get next line is not starting with a table */
		{
			if (!start)
			{
				tree->next = create_node();
				tree = tree->next;
			}

			tree->type = NODE;
			tree->status = ONCE;

			i = 0;
			while (ft_isalpha(tmp[i]))
				i += 1;
			tree->str = ft_strndup(tmp, i);

			tree->leaf = NULL;
			function_to_create_leaf_child_node(tree, tree_head, tmp);

			start = 0;
		}
		else
		{
			i = 0;
			while (tmp[i] == '\t')
				i += 1;
			tmp = ft_strsub(tmp, i, ft_strlen(tmp) - i);
			ft_printf("tmp : %s\n", tmp);
		}
	}

	print_tree(tree, 0);
	return (0);
}

// int			main(void)
// {
// 	char un = 'a';
// 	char *deux = "Hello World";
// 	ft_printf("sizeof(un) = %d, sizeof(deux) = %d", sizeof(un), sizeof(deux));
// 	return (0);
// }
