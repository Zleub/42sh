/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhispa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbir <gbir@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 14:52:34 by gbir              #+#    #+#             */
/*   Updated: 2014/02/15 14:54:08 by gbir             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iswhispa(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
			c == '\r')
		return (1);
	return (0);
}