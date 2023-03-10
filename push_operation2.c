/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_operation2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 17:26:41 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/05 16:36:41 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_action(t_dlist **b)
{
	ft_swap(b);
	printf("sb\n");
}

void	ss_action(t_dlist **a, t_dlist **b)
{
	ft_swap(a);
	ft_swap(b);
	printf("ss\n");
}

void	ra_action(t_dlist **a)
{
	ft_rotate(a);
	printf("ra\n");
}

void	rb_action(t_dlist **b)
{
	ft_rotate(b);
	printf("rb\n");
}

void	rr_action(t_dlist **a, t_dlist **b)
{
	ft_rotate(a);
	ft_rotate(b);
	printf("rr\n");
}
