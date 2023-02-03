/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_operation1.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 17:16:28 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/03 15:28:34 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*sa_action(t_dlist *a)
{
	a = ft_swap(a);
	printf("sa\n");
	return (a);
}

t_dlist	*sb_action(t_dlist *b)
{
	b = ft_swap(b);
	printf("sb\n");
	return (b);
}

t_dlist	*ra_action(t_dlist *a)
{
	a = ft_rotate(a);
	printf("ra\n");
	return (a);
}

t_dlist	*rb_action(t_dlist *b)
{
	b = ft_rotate(b);
	printf("rb\n");
	return (b);
}
