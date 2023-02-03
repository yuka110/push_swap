/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_operation2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 17:26:41 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/03 16:04:32 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*rra_action(t_dlist *a)
{
	a = ft_reverser(a);
	printf("rra\n");
	return (a);
}

t_dlist	*rrb_action(t_dlist *b)
{
	b = ft_reverser(b);
	printf("rrb\n");
	return (b);
}

t_dlist	*pb_action(t_dlist *a, t_dlist *b)
{
	t_dlist	*tmp;

	if (!a)
		return (NULL);
	tmp = a;
	a = a->next;
	a->prev = NULL;
	if (!a)
		return (NULL);
	b = pop_push(b, tmp);
	printf("pb\n");
	return (b);
}

t_dlist	*pa_action(t_dlist *b, t_dlist *a)
{
	t_dlist	*tmp;

	tmp = b;
	b = b->next;
	b->prev = NULL;
	if (!b)
		return (NULL);
	dlstadd_front(&a, tmp);
	printf("pa\n");
	return (a);
}

// t_dlist	*rrr_action(t_dlist *a, t_dlist *b)
// {
    
// }