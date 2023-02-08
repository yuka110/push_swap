/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_radix.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 16:00:55 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/08 18:11:19 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_dlist **a, t_dlist **b, int len)
{
	t_dlist	*p1;
	int		max_num;
	int		max_bit;
	int		digit;
	int		i;

	max_num = dlst_max(*a);
	max_bit = 0;
	digit = 0;
	while (max_num)
	{
		max_num = max_num >> 1;
		++max_bit;
	}
	//printf("%d\n", max_bit);
	while (digit <= max_bit)
	{
		p1 = *a;
		i = 0;
		while (p1->next && i < len)
		{
			if (((p1->num >> digit) & 1) == 1)
				ra_action(a);
			else
				pb_action(a, b);
			++i;
			p1 = *a;
		}
		// printf("a:");
		// print_num(*a);
		// printf("b:");
		// print_num(*b);
		while (*b)
			pa_action(b, a);
		++digit;
	}
}
