/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_trio.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 15:58:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/01 17:15:46 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*which_cases(t_dlist *lst)
{
	if (lst->num == 0)
	{
		lst = sa_action(lst);
		lst = ra_action(lst);	
	}
	if (lst->num == 1 && (lst->next)->num == 2)
		lst = rra_action(lst);
	if (lst->num == 1 && (lst->next)->num == 0)
		lst = sa_action(lst);
	if (lst->num == 2 && (lst->next)->num == 0)
		lst = ra_action(lst);	
	if (lst->num == 2 && (lst->next)->num == 1)
	{
		lst = sa_action(lst);	
		lst = rra_action(lst);
	}
	return (lst);
}

t_dlist	*ft_swap(t_dlist *lst)
{
	t_dlist	*p1;
	t_dlist	*p2;

	p1 = lst;
	p2 = lst->next;
	p1->next = p2->next;
	p2->prev = NULL;
	p2->next = p1;
	p1->prev = p2;
	lst = p2;
	printf("sa\n");
	return (lst);
}

t_dlist	*ft_rotate(t_dlist *lst)
{
	t_dlist	*p1;
	t_dlist	*p2;
	t_dlist	*last;

	p1 = lst;
	p2 = lst->next;
	last = lst;
	while (last->next)
		last = last->next;
	p1->next = NULL;
	p1->prev = last;
	last->next = p1;
	p2->prev = NULL;
	lst = p2;
	printf("ra\n");
	return (lst);
}

t_dlist	*ft_reverser(t_dlist *lst)
{
	t_dlist	*p1;
	t_dlist	*p2;

	p1 = lst;
	p2 = lst;
	while (p1->next)
		p1 = p1->next;
	p1->next = p2;
	p1->prev = NULL;
	p2->prev = p1;
	while (p2->next)
		p2 = p2->next;
	p2->next = NULL;
	lst = p1;
	printf("rra\n");
	return (lst);
}

t_dlist	*ft_push(t_dlist *lst1, t_dlist *lst2)
{
	
}
