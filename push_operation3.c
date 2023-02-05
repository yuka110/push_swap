/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_operation3.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/05 15:56:28 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/05 16:36:37 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_action(t_dlist **a)
{
	ft_reverser(a);
	printf("rra\n");
}

void	rrb_action(t_dlist **b)
{
	ft_reverser(b);
	printf("rrb\n");
}

void	rrr_action(t_dlist **a, t_dlist **b)
{
	ft_reverser(a);
	ft_reverser(b);
	printf("rrr\n");
}

void	pb_action(t_dlist **a, t_dlist **b)
{
	ft_push(b, a);
	printf("pb\n");
}

void	pa_action(t_dlist **b, t_dlist **a)
{
	ft_push(a, b);
	printf("pa\n");
}
