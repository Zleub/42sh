/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nosh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 21:41:20 by adebray           #+#    #+#             */
/*   Updated: 2014/02/14 23:13:52 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOSH_H
# define NOSH_H

# include <libft.h>
# include <ft_printf.h>
# include <gnl.h>
# include <term.h>

typedef struct		s_gnl
{
	char			c;
	struct s_gnl	*next;
}					t_gnl;

int		ft_putschar(int c);

#endif
