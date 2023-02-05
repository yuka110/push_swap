/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_trio.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 15:58:22 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/05 16:54:24 by yitoh         ########   odam.nl         */
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
	trd = (((*lst)->next)->next)->num;
	printf("fst=%d, sec=%d, trd=%d\n", fst, sec, trd);
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
	{
		sa_action(lst);
		rra_action(lst);
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
*/
