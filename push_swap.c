/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:52:29 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/05 16:46:21 by yitoh         ########   odam.nl         */
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

void	simple_num(t_dlist *a, int len)
{
	int		i;
	int		min;
	t_dlist	*p1;
	t_dlist	*p2;

	i = 0;
	min = -2147483648;
	while (i < len)
	{
		p1 = a;
		while (p1->next && p1->data <= min)
			p1 = p1->next;
		while (p1->next && p2)
		{
			p2 = p1->next;
			while (p2->next && (p2->data <= min))
				p2 = p2->next;
			while (p2->next && ((p1->data < p2->data) || p2->data <= min))
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

void	print_num(t_dlist	*lst)
{
	t_dlist	*ptr;

	ptr = lst;
	while (ptr)
	{
		printf("%d ", ptr->num);
		ptr = ptr->next;
	}
	printf("\n");
}
