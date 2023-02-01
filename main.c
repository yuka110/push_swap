/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:57:15 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/01 16:53:48 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*ptr;
	int		len;

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
	a = which_cases(a);
	ptr = a;
	while (ptr)
	{
		printf(":%d ", ptr->num);
		ptr = ptr->next;
	}
	// if (len <= 6)
	// 	a = small_sort(a, len);
	//a = big_sort(a);
	free_dlist(a);
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





*/