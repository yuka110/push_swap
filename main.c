/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:57:15 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/03 16:07:14 by yitoh         ########   odam.nl         */
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
	ptr = a;
	while (ptr)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	ptr = a;
	if (error_check(ptr) == 0)
		return (0);
	ptr = a;
	if (all_sorted(ptr) == 1)
		return (printf("\n"), 0);
	len = dlst_size(a);
	printf("len = %d\n", len);
	simple_num(a, len);
	ptr = a;
	while (ptr)
	{
		printf("%d ", ptr->num);
		ptr = ptr->next;
	}
	printf("\n");
	b = pb_action(a, b);
	ptr = a;
	while (ptr)
	{
		printf("a%d ", ptr->num);
		ptr = ptr->next;
	}
	ptr = b;
	while (ptr)
	{
		printf("b%d ", ptr->num);
		ptr = ptr->next;
	}
	// a = which_cases(a);
	// ptr = a;
	// while (ptr)
	// {
	// 	printf(":%d ", ptr->num);
	// 	ptr = ptr->next;
	// }
	// if (len <= 6)
	// 	a = small_sort(a, len);
	//a = big_sort(a);
	free_dlist(a);
	free_dlist(b);
}

// % ./push_swap 38479 378 899
// 38479 378 899 
// len = 3
// 2 0 1 
// pb
// push_swap(13571,0x110e875c0) malloc: *** error for object 0x7ff0d3400640: pointer being freed was not allocated
// push_swap(13571,0x110e875c0) malloc: *** set a breakpoint in malloc_error_break to debug
// a2 a0 a1 b38479 zsh: abort      ./push_swap 38479 378 899

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