/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:57:15 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/23 13:45:03 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	t_list	*ptr;

	list = parse_num(argc, argv);
	if (!list)
		return (0);
	ptr = list;
	while (ptr)
	{
		printf("%s ", ptr->content);
		ptr = ptr->next;
	}
	printf("\n");
}

/*
1 
2
3

1
3
2

2
1
3

2
3
1

3
1
2

3
2
1

*/