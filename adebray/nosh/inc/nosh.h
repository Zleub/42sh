/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nosh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 21:41:20 by adebray           #+#    #+#             */
/*   Updated: 2014/02/23 02:08:57 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOSH_H
# define NOSH_H

# include <libft.h>
# include <ft_printf.h>
# include <gnl.h>
# include <term.h>

typedef struct		s_clist
{
	char			c;
	struct s_clist	*next;
	struct s_clist	*prev;
}					t_clist;

int					ft_putschar(int c);
void				print_clist(t_clist *head);
t_clist				*create_clist(void);
void				free_clist(t_clist *elem);
int					lign_nb(int cmp, int col_size);

#endif
