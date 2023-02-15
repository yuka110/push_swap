/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:52:29 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/15 16:21:58 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_sorted(t_dlist *lst)
{
	t_dlist	*p1;
	t_dlist	*p2;

	p1 = lst;
	while (p1->next)
	{
		p2 = p1->next;
		if (p1->data > p2->data)
			return (0);
		p1 = p1->next;
	}
	return (1);
}

void	simple_num(t_dlist **a, int len, int min)
{
	int		i;
	t_dlist	*p1;
	t_dlist	*p2;

	i = 0;
	while (i < len)
	{
		p1 = *a;
		while (p1->next && p1->data <= min)
			p1 = p1->next;
		while (p1->next && p2)
		{
			p2 = p1->next;
			while (p2->next && (p1->data < p2->data || p2->data <= min))
				p2 = p2->next;
			if (p1->data > p2->data && p2->data > min)
				p1 = p2;
			if (!p2->next || p2->data <= min)
				break ;
		}
		p1->num = i;
		++i;
		min = p1->data;
	}
}

int	bit_count(int nbr)
{
	int		bit;

	bit = 0;
	while (nbr)
	{
		nbr = nbr >> 1;
		++bit;
	}
	return (bit);
}

void	radix_sort(t_dlist **a, t_dlist **b, int len)
{
	t_dlist	*p1;
	int		max_bit;
	int		digit;
	int		i;

	max_bit = bit_count(dlst_max(*a));
	digit = 0;
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
		while (*b)
			pa_action(b, a);
		++digit;
	}
}

void	free_dlist(t_dlist *lst)
{
	t_dlist	*ptr;

	ptr = lst->next;
	while (ptr)
	{
		free (lst);
		lst = ptr;
		ptr = lst->next;
	}
}
