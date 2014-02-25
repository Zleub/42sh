/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_clist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 02:06:10 by adebray           #+#    #+#             */
/*   Updated: 2014/02/25 13:23:26 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nosh.h>

void				dprint_clist(int fd, t_clist *head)
{
	if (!head)
		return ;
	while (head->next)
	{
		write(fd, &head->c, 1);
		head = head->next;
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
