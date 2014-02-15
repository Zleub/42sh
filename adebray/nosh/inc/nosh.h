/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nosh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 21:41:20 by adebray           #+#    #+#             */
/*   Updated: 2014/02/15 06:50:49 by adebray          ###   ########.fr       */
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
}					t_clist;

int		ft_putschar(int c);

#endif
