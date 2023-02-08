/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:57:15 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/08 19:25:15 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*ptr;
	t_dlist	*b;
	int		len;

	b = NULL;
	a = parse_num(argc, argv);
	if (!a)
		return (0);
	// ptr = a;
	// while (ptr)
	// {
	// 	printf("%d ", ptr->data);
	// 	ptr = ptr->next;
	// }
	// printf("\n");
	ptr = a;
	if (error_check(ptr) == 0)
		return (0);
	ptr = a;
	if (all_sorted(ptr) == 1)
		return (printf("\n"), 0);
	len = dlst_size(a);
	simple_num(a, len);
	//print_num(a);
	if (len < 6)
		small_sort(&a, &b, len);
	else
		radix_sort(&a, &b, len);
	//print_num(a);
	free_dlist(a);
	if (b)
		free_dlist(b);
}

/*

5. line them up based on the order_id 

1 2 3	5 4 6
1 2 4 	3 5 6
1 2 5 	3 4 6
1 2 6 	3 4 5


1 3 4	2 5 6
1 
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3
1 3

0xxxxx OK
x0xxxx sa OK
xx0xxx 
xxx0xx
xxxx0x
xxxxx0


0, 1, 2: find 3
0, 1: find 2
0: find 1

if (len - 4)
4; 0
0132
1023
1203



5; 01 
6; 012
*/