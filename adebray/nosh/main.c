/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arno <Arno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/02/17 17:16:29 by Arno             ###   ########.fr       */
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

int					line_edition(void)
{
	char			buf[5] = {0};
	t_clist			*tmp;
	t_clist			*head;

	tmp = create_clist();
	head = tmp;
	// tputs(tgetstr("sc", NULL), 1, ft_putschar);
	while (read(0, buf, 4) > 0)
	{
		if (0 <= buf[0] && buf[1] == '\0')
		{
			if (buf[0] == 10)
			{
				free_clist(head);
				return (0);
			}
			else if (buf[0] == 127)
			{
				if (tmp->prev)
				{
					if (tmp->prev->prev)
					{
						t_clist *todel;
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
					else
						;
				}
			}
			else if (buf[0] == 27)
			{
				return (-1);
			}
			else
			{
				tmp->c = buf[0];
				tmp->next = create_clist();
				tmp->next->prev = tmp;
				tmp = tmp->next;
			}
		}
		else
			;
		// ft_printf("%s\tYou wrote : '%d.%d.%d.%d.%d'\n", buf, buf[0], buf[1], buf[2], buf[3], buf[4]);
		// tputs(tgetstr("rc", NULL), 1, ft_putschar);
		tputs(tgetstr("cr", NULL), 1, ft_putschar);
		tputs(tgetstr("dl", NULL), 1, ft_putschar);
		print_clist(head);
		ft_strclr(buf);

	}
	return (0);
}

int					no_sh(void)
{
	while (42)
	{
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
