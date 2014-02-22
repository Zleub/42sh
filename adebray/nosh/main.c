/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/02/22 07:09:21 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nosh.h>

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

void				print_clist(t_clist *head)
{
	if (!head)
		return ;
	while (head->next)
	{
		ft_printf("%c", head->c);
		head = head->next;
	}
	// ft_printf("\n");
}

t_clist				*create_clist(void)
{
	t_clist			*gnl;

	gnl = (t_clist*)malloc(sizeof(t_clist));
	gnl->c = -1;
	gnl->next = NULL;
	gnl->prev = NULL;
	return (gnl);
}

void				free_clist(t_clist *elem)
{
	if (elem->next)
		free_clist(elem->next);
	if (elem)
	{
		free(elem);
		elem = NULL;
	}
}

int					lign_nb(int cmp, int col_size)
{
	int		i;

	i = 0;
	while (cmp > col_size)
	{
		cmp -= col_size;
		i += 1;
	}
	return (i);
}

void			is_backspace(t_clist *tmp, t_clist *head)
{
	t_clist *todel;

	if (tmp->prev)
	{

		if (tmp->prev->prev)
		{
			todel = tmp->prev;
			tmp->prev->prev->next = tmp;
			tmp->prev = tmp->prev->prev;
			free (todel);
		}
		else if (tmp->prev)
		{
			free (tmp->prev);
			tmp->prev = NULL;
			head = tmp;
		}
		tputs(tgetstr("le", NULL), 1, ft_putschar); /* move left */
		tputs(tgetstr("dc", NULL), 1, ft_putschar); /* clear char */
	}
}

t_clist			*map_ascii(char *buf, t_clist *head, t_clist *tmp)
{
	if (buf[0] == 10) /* is \n */
	{
		free_clist(head);
		return (NULL);
	}
	else if (buf[0] == 127) /* is backspace */
		is_backspace(tmp, head);
	else if (buf[0] == 27) /* is esc */
	{
		ft_printf("\n");
		return (NULL);
	}
	else if (buf[0] == 9) /* horizontale tabulation */
		;
	else
	{
		write(1, &buf[0], 1);
		tmp->c = buf[0];
		tmp->next = create_clist();
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	return (tmp);
}

int					line_edition(void)
{
	char			buf[5] = {0};
	t_clist			*tmp;
	t_clist			*head;

	tmp = create_clist();
	head = tmp;
	while (read(0, buf, 4) > 0)
	{
		if (0 <= buf[0] && buf[1] == '\0')
		{
			tmp = map_ascii(buf, head, tmp);
			if (!tmp)
				return (-1);
		}
		ft_strclr(buf);
	}
	return (0);
}

int					no_sh(void)
{
	while (42)
	{
		ft_printf("prompt ->");
		if (line_edition() == -1)
			return (0);
		ft_printf("\n");
	}


	return (0);
}

int					main(int argc, char** argv, char **environ)
{
	(void)argc;
	(void)argv;

	if (!*environ)
	{
		ft_printf("Go get urself an env mtherfucker\n");
		return (-1);
	}
	else
	{
		tswitch(1);
		no_sh();
	}
	tswitch(0);
	return (0);
}
