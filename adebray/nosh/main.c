/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 19:41:35 by adebray           #+#    #+#             */
/*   Updated: 2014/02/15 06:14:20 by adebray          ###   ########.fr       */
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

void				print_gnl(t_gnl *head)
{
	while (head->next)
	{
		ft_printf("%c", head->c);
		head = head->next;
	}
	// ft_printf("\n");
}

t_gnl				*create_gnl(void)
{
	t_gnl			*gnl;

	gnl = (t_gnl*)malloc(sizeof(t_gnl));
	gnl->c = -1;
	gnl->next = NULL;
	return (gnl);
}

int					line_edition(void)
{
	char			buf[5] = {0};
	t_gnl			*tmp;
	t_gnl			*head;

	tmp = create_gnl();
	head = tmp;
	tputs(tgetstr("sc", NULL), 1, ft_putschar);
	while (read(0, buf, 4) > 0)
	{
		if (0 <= buf[0] && buf[1] == '\0')
		{
			if (buf[0] == 10)
				return (0);
			tmp->c = buf[0];
			tmp->next = create_gnl();
			tmp = tmp->next;
		}
		else
		{
			ft_printf("%s\tYou wrote : '%d.%d.%d.%d.%d'\n", buf, buf[0], buf[1], buf[2], buf[3], buf[4]);
			// print_gnl(head);
		}
		tputs(tgetstr("rc", NULL), 1, ft_putschar);

		print_gnl(head);
		ft_strclr(buf);

	}
	return (0);
}

int					no_sh(void)
{
	while (42)
	{
		tputs(tgetstr("cr", NULL), 1, ft_putschar);
		tputs(tgetstr("dl", NULL), 1, ft_putschar);
		line_edition();
	}
	return (0);
}

#include <sys/ioctl.h>

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
