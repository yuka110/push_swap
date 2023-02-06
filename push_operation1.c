/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_operation1.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 17:16:28 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/06 20:12:37 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_dlist **lst)
{
	t_dlist	*p1;
	t_dlist	*p2;

	p1 = *lst;
	p2 = (*lst)->next;
	p1->next = p2->next;
	p2->prev = NULL;
	p2->next = p1;
	p1->prev = p2;
	*lst = p2;
}

void	ft_rotate(t_dlist **lst)
{
	t_dlist	*p1;
	t_dlist	*p2;
	t_dlist	*last;

	p1 = *lst;
	p2 = (*lst)->next;
	last = *lst;
	while (last->next)
		last = last->next;
	p1->next = NULL;
	p1->prev = last;
	last->next = p1;
	p2->prev = NULL;
	*lst = p2;
}

void	ft_reverser(t_dlist **lst)
{
	t_dlist	*p1;
	t_dlist	*p2;

	p1 = *lst;
	p2 = *lst;
	while (p1->next)
		p1 = p1->next;
	p1->next = p2;
	(p1->prev)->next = NULL;
	p1->prev = NULL;
	p2->prev = p1;
	*lst = p1;
}

void	ft_push(t_dlist **dst, t_dlist **src)
{
	t_dlist	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	if (*src)
		(*src)->prev = NULL;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
}

void	sa_action(t_dlist **a)
{
	ft_swap(a);
	printf("sa\n");
}
