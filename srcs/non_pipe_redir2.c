/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_pipe_redir2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/05 21:11:57 by mngomane          #+#    #+#             */
/*   Updated: 2015/03/17 13:21:20 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "ftsh.h"

static t_sent	*new_sent(t_sent *tab)
{
	t_sent		*tmp;

	tmp = (t_sent *)malloc(sizeof(t_sent));
	tmp->word = ft_strdup("cat");
	tmp->index = 1;
	tmp->next = tab;
	return (tmp);
}

void			red_left(t_entry *ent, t_env **envl, t_sent ***tab)
{
	t_sent		*tmp;

	if (!(*tab)[2])
	{
		(*tab)[1] = new_sent((*tab)[1]);
		if ((ent->pid = fork()) == -1)
			write(2, "42sh: fork error (sub_main2.c).\n", 6);
		if (!(ent->pid))
			ft_son(ent, envl, &((*tab)[1]), &(ent->bin));
		else
			ft_father(ent, envl, &(*tab)[1]);
	}
	else
	{
		tmp = new_sent((*tab)[2]);
		(*tab)[2]->next = NULL;
		(*tab)[2]->index = 2;
		(*tab)[2] = tmp;
		tmp = (*tab)[1];
		(*tab)[1] = (*tab)[2];
		(*tab)[2] = tmp;
		sub_pipe_fork(ent, envl, *tab);
	}
}
