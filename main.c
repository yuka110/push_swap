/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:57:15 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/26 15:26:30 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*list;
	t_dlist	*ptr;
	int		check;

	list = parse_num(argc, argv);
	if (!list)
		return (0);
	ptr = list;
	while (ptr)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	check = error_check(list);
	free_list(list);
}


/*
1. parse input in dlink list in int (ft_atoi)
2. error check
3. compare values
4. assign order_id form (0 - num of nodes)
5. line them up based on the order_id 
*/