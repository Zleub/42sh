/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebray <adebray@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 02:24:18 by adebray           #+#    #+#             */
/*   Updated: 2014/02/13 16:25:41 by adebray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
** USE OF PTR NEED CAST MOST TIME
*/

typedef struct	s_list
{
	void		*ptr;
	void		*next;
}				t_list;

t_list		*ft_lstinit(void)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
	node->ptr = NULL;
	node->next = NULL;
	return (node);
}

// void		ft_lstprt()

// t_list		*ft_lstcpy(t_list *src)
// {
// 	t_list	*dst;

// 	dst = (t_list*)malloc(sizeof(t_list));
// 	dst->ptr = src->ptr;
// 	dst->next = src->next;
// 	return(dst);
// }

t_list		*ft_lstdup(t_list *src)
{
	t_list	*dst;

	dst = (t_list*)malloc(sizeof(t_list));
	dst->ptr = src->ptr;
	dst->next = src->next;
	return(dst);
}

// void		ft_lstup(t_list *list, t_list *node)
// {
// 	list->
// }

int			main(void)
{
	t_list	*head;
	head = ft_lstinit();
	head->ptr = "real test";
	printf("head %p\n", head);
	printf("head->ptr %p\n", head->ptr);

	t_list	*cpy;
	cpy = ft_lstdup(head);
	head->next = cpy;
	printf("cpy %p\n", cpy);
	printf("cpy->ptr %p\n", cpy->ptr);
	printf("%p\n", head->next);

	t_list	*tmp;
	tmp = head->next;
	tmp->ptr = "prout";
	printf("tmp %p\n", tmp);
	printf("tmp->ptr %p\n", tmp->ptr);

	return (0);
}
