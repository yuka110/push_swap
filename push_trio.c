/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_trio.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 15:58:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/21 10:35:47 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_dlist **lst)
{
	int	fst;
	int	sec;
	int	trd;

	fst = (*lst)->num;
	sec = ((*lst)->next)->num;
	if (dlst_size(*lst) == 2 && fst > sec)
		return (sa_action(lst));
	if ((dlst_size(*lst) == 2 && sec > fst) || all_sorted(*lst) == 1)
		return ;
	trd = (((*lst)->next)->next)->num;
	if (fst < sec && fst < trd)
	{
		sa_action(lst);
		ra_action(lst);
	}
	if (fst < sec && sec > trd && trd < fst)
		rra_action(lst);
	if (fst > sec && sec < trd && trd > fst)
		sa_action(lst);
	if (fst > sec && sec < trd && trd < fst)
		ra_action(lst);
	if (fst > sec && sec > trd && trd < fst)
		return (sa_action(lst), rra_action(lst));
}

void	small_sort(t_dlist **a, t_dlist **b, int len)
{
	int		search;
	int		temp_len;

	search = 0;
	temp_len = len;
	while (len > 3 && search < len - 3)
	{
		push_top(a, temp_len, search, 1);
		pb_action(a, b);
		search++;
		temp_len--;
	}
	sort_three(a);
	while (search > 0)
	{
		pa_action(b, a);
		search--;
	}
	return ;
}

void	push_top(t_dlist **a, int len, int index, int i)
{
	t_dlist	*ptr;

	ptr = *a;
	while (ptr && i <= len)
	{
		if (i == 1 && ptr->num == index)
			return ;
		if (i == 2 && ptr->num == index)
			return (sa_action(a));
		if (i == len - 1 && ptr->num == index)
			return (rra_action(a), rra_action(a));
		if (i == 3 && ptr->num == index)
		{
			while (i < len)
			{
				ra_action(a);
				i++;
			}
			return ;
		}
		if (ptr && i == len && ptr->num == index)
			return (rra_action(a));
		ptr = ptr->next;
		i++;
	}
}
