/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:52:29 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/03 15:51:54 by yitoh         ########   odam.nl         */
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
/*
t_dlist	*small_sort(t_dlist *a, int len)
{
	int		get;
	t_dlist	*p;

	get = 0;
	p = a;
	if (len <= 3)
		tiny
	if (len == 4)
		a = sort_four(p);
	if (len == 5)
		sort_five(p);
	if (len == 6)
		sort_six(p);
	

	//find min
	// move it to top of a;
	//push it to b;
		a = which_cases(a);
	
	
}


t_dlist	*sort_four(t_dlist *a)
{
	int		get;
	t_dlist	*p;
	t_dlist *b;

	p = a;
	if (p->num == 0)
		pb_action(p, b);
		


}
*/