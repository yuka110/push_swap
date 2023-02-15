/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:57:15 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/10 13:19:59 by yitoh         ########   odam.nl         */
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
