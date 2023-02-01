/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_operation2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 17:26:41 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/01 17:32:49 by yitoh         ########   odam.nl         */
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

// t_dlist	*rr_action(t_dlist *a, t_dlist *b)
// {
    
// }

// t_dlist	*rrr_action(t_dlist *a, t_dlist *b)
// {
    
// }