/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_error.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:25:07 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/15 16:23:02 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*over_twoargs(int argc, char **argv, t_dlist *lst)
{
	int		i;
	t_dlist	*new;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			return (NULL);
		new = dlstnew(ft_atoi(argv[i]));
		dlstadd_back(&lst, new);
		++i;
	}
	return (lst);
}

t_dlist	*parse_num(int argc, char **argv)
{
	t_dlist	*lst;

	lst = NULL;
	if (argc <= 1)
		return (ft_printf("Error\n"), NULL);
	if (non_integer(argc, argv) == 0)
		return (ft_printf("Error\n"), NULL);
	if (argc == 2)
	{
		lst = split_parse(argv[1]);
		if (!lst)
			return (NULL);
		if (dlst_size(lst) == 1)
			return (ft_printf("\n"), NULL);
		return (lst);
	}
	lst = over_twoargs(argc, argv, lst);
	if (!lst)
		return (ft_printf("Error\n"), NULL);
	return (lst);
}

t_dlist	*split_parse(char *str)
{
	char	**arr;
	t_dlist	*lst;
	t_dlist	*new;
	int		i;

	arr = ft_split(str, ' ');
	if (!arr)
		return (NULL);
	i = 0;
	lst = NULL;
	while (arr[i])
	{
		new = dlstnew(ft_atoi(arr[i]));
			if (!new)
				return (NULL);
		dlstadd_back(&lst, new);
		free (arr[i]);
		++i;
	}
	free (arr);
	return (lst);
}

int	error_check(t_dlist	*lst)
{
	t_dlist	*pin;
	t_dlist	*pon;

	pin = lst->next;
	pon = lst;
	while (pon && pin)
	{
		while (pin)
		{
			if (pon->data == pin->data)
				return (ft_printf("Error\n"), 0);
			pin = pin->next;
		}
		pon = pon->next;
		pin = pon->next;
	}
	pin = lst;
	while (pin)
	{
		if (pin->data > 2147483647 //to long or somthing dunno
			|| pin->data < -2147483648)
			return (ft_printf("Error\n"), 0);
		pin = pin->next;
	}
	return (1);
}

int	non_integer(int argc, char	**argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '+' || argv[i][0] == '-')
			++j;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != ' ')
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}
