/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/02/25 18:09:54 by Arno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nosh.h>

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

t_clist			*map_ascii(char *buf, t_clist **head, t_clist *tmp)
{
	t_clist		*new;

	if (buf[0] == 10) /* is \n */
	{
		write(1, "\n", 1);
		ft_printf("prompt ->");
		free_clist(*head);
		*head = create_clist();
		return (*head);
	}
	else if (buf[0] == 127) /* is backspace */
		is_backspace(tmp, *head);
	else if (buf[0] == 27) /* is esc */
	{
		int fd = open("dump", O_CREAT | O_TRUNC | O_WRONLY);
		(void)fd;
		ft_printf("\n");
		return (NULL);
	}
	else if (buf[0] == 9) /* horizontale tabulation */
		;
	else
	{
		if (tmp->c == -1)
		{
			write(1, &buf[0], 1);
			tmp->c = buf[0];
			tmp->next = create_clist();
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		else
		{
			tputs(tgetstr("im", NULL), 1, ft_putschar); /* mode insersion on */
			tputs(tgetstr("ic", NULL), 1, ft_putschar); /* insert char */

			write(1, &buf[0], 1);
			tputs(tgetstr("ip", NULL), 1, ft_putschar); /* finish insert char */

			tputs(tgetstr("ei", NULL), 1, ft_putschar); /* mode insertion off */
			new = create_clist();
			new->c = buf[0];
			if (tmp->prev)
				tmp->prev->next = new;
			else
				*head = new;
			new->prev = tmp->prev;
			tmp->prev = new;
			new->next = tmp;
		}
	}
	return (tmp);
}

t_clist			*map_noascii(char *buf, t_clist *head, t_clist *tmp)
{
	(void)head;
	(void)tmp;
	// if (KEYUP)
		// ft_printf("KEY UP");
	// else if (KEYDW)
	// 	ft_printf("KEY DOWN");
	if (KEYRT)
	{
		if (tmp->next)
		{
			tmp = tmp->next;
			tputs(tgetstr("nd", NULL), 1, ft_putschar); /* move right */
		}
		return (tmp);
	}
	else if (KEYLF)
	{
		if (tmp->prev)
		{
			tmp = tmp->prev;
			tputs(tgetstr("le", NULL), 1, ft_putschar); /* move left */
		}
		return (tmp);
	}
	// ft_printf("\nprompt->");
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
			tmp = map_ascii(buf, &head, tmp);
			if (!tmp)
				return (-1);
		}
		else
		{
			tmp = map_noascii(buf, head, tmp);
		}
		ft_strclr(buf);
		int fd = open("dump", O_CREAT | O_TRUNC | O_WRONLY);
		dprint_clist(fd, head);
		close(fd);
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
