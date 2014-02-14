/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 17:14:51 by gbir              #+#    #+#             */
/*   Updated: 2014/01/26 13:36:54 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

/*
** this function free all arguments past
** dont forget to inform nb (number of arguments)
*/
int		allfree(int nb, ...)
{
	va_list	ap;
	void	*to_free;

	va_start(ap, nb);
	while (nb-- > 0)
	{
		to_free = va_arg(ap, void *);
		free(to_free);
	}
	va_end(ap);
	return (1);
}
