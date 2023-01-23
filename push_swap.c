/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:52:29 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/23 13:47:47 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse_num(int argc, char **argv)
{
	int		i;
	t_list	*lst;
	t_list	*new;

	i = 1;
	lst = NULL;
	if (argc <= 1)
		return (0);
	while (i < argc)
	{
		new = ft_lstnew(argv[i]);
		// if (!new && lst)
		// 	free ()
		ft_lstadd_back(&lst, new);
		++i;
	}
	return (lst);
}



void	error_check()
{
	
}
// void	free_list(t_list **lst, int i)
// {
// 	while (i != 0)
// 	{
// 		free ()
// 	}
// }