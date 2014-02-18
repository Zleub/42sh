/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/02/18 11:22:32 by adebray          ###   ########.fr       */
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

#include <stdio.h>

int					line_edition(void)
{
	char			buf[5] = {0};
	t_clist			*tmp;
	t_clist			*head;
	int				cmp;

	tmp = create_clist();
	head = tmp;
	cmp = ft_strlen("prompt ->");
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
				}
			}
			else if (buf[0] == 27)
			{
				ft_printf("\n");
				return (-1);
			}
			else
			{
				if (buf[0] == 9) /* horizontale tabulation */
				{
					if (cmp % 8 != 0)
						while (cmp % 8 != 0)
							cmp += 1;
					else
						cmp += 8;
				}
				else
					cmp += 1;
				tmp->c = buf[0];
				tmp->next = create_clist();
				tmp->next->prev = tmp;
				tmp = tmp->next;
			}
		}

		dprintf(3, "-> PRITN 1\n");
		// sleep(1);

		// ft_printf("%s\tYou wrote : '%d.%d.%d.%d.%d'\n", buf, buf[0], buf[1], buf[2], buf[3], buf[4]);
		// tputs(tgetstr("rc", NULL), 1, ft_putschar);
		tputs(tgetstr("cr", NULL), 1, ft_putschar); /* begin of line */
		dprintf(3, "PRITN 2\n");
		// sleep(1);
		int col_size;
		int tmp;
		dprintf(3, "cmp list : %d\n", cmp);


		col_size =  tgetnum("co");
		tmp = 0;
		dprintf(3, "PRITN 3\n");
		dprintf(3, "cmp + propmt: %d col_size : %d\n", cmp, col_size);
		if (cmp > col_size)
		{
					dprintf(3, "PRITN 4\n");
							// sleep(1);

			tmp = cmp / col_size;
			dprintf(3, "\n tmp %d \n", tmp);
			while (tmp-- > 0)
			{
				dprintf(3, "PRITN 5\n");
							sleep(1);
				// ft_printf("test 1\n");
				tputs(tgetstr("up", NULL), 1, ft_putschar); /* up cursor */
			}
			tmp = cmp / col_size;
			while (tmp-- > 0)
			{
						dprintf(3, "PRITN 5\n");
						sleep(1);
				// ft_printf("test 2\n");
				tputs(tgetstr("dl", NULL), 1, ft_putschar); /* clear line */
			}
		}
				// tputs(tgetstr("dl", NULL), 1, ft_putschar); /* clear line */
		dprintf(3, "PRITN 6\n");
						sleep(1);

		ft_printf("prompt ->");

		print_clist(head);
		// ft_printf("\n%d", cmp / col_size);
		ft_strclr(buf);

	}
	return (0);
}

int					no_sh(void)
{
	ft_printf("prompt ->");
	while (42)
	{
		// ft_printf("prompt ->");
		if (line_edition() == -1)
			return (0);
		ft_printf("\n");
	}
	return (0);
}

	#include <fcntl.h>

int					main(int argc, char** argv, char **environ)
{
	(void)argc;
	(void)argv;

	open("dump", O_CREAT | O_TRUNC | O_WRONLY, 00755);
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
