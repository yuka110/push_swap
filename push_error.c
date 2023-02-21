/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_error.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:25:07 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/21 10:34:46 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*over_twoargs(int argc, char **argv, t_dlist *lst)
{
	int			i;
	long long	nbr;
	t_dlist		*new;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			return (NULL);
		nbr = ft_atolong(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (NULL);
		new = dlstnew(nbr);
		if (!new && lst)
			free_dlist(lst);
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
		return (NULL);
	if (non_integer(argc, argv) == 0 && argc > 2)
		return (ft_printf("Error\n"), NULL);
	if (argc == 2)
	{
		lst = split_parse(argv[1], lst);
		if (!lst)
			return (ft_printf("Error\n"), NULL);
		if (dlst_size(lst) == 1)
			return (ft_printf("Error\n"), NULL);
		return (lst);
	}
	lst = over_twoargs(argc, argv, lst);
	if (!lst)
		return (ft_printf("Error\n"), NULL);
	return (lst);
}

t_dlist	*split_parse(char *str, t_dlist *lst)
{
	char	**arr;
	t_dlist	*new;
	int		i;

	arr = ft_split(str, ' ');
	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		++i;
	if (non_integer(i, arr) == 0)
		return (free_arr(arr), NULL);
	i = 0;
	while (arr[i])
	{
		if (ft_atolong(arr[i]) > 2147483647
			|| ft_atolong(arr[i]) < -2147483648)
			return (free_arr(arr), NULL);
		new = dlstnew(ft_atoi(arr[i]));
		if (!new)
			return (free_dlist(lst), NULL);
		dlstadd_back(&lst, new);
		++i;
	}
	return (free_arr(arr), lst);
}

int	dup_error(t_dlist	*lst)
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
	return (1);
}

int	non_integer(int argc, char	**argv)
{
	int		i;
	int		j;
	char	**arr;

	i = 1;
	arr = argv;
	while (i < argc)
	{
		j = 0;
		if (arr[i][0] == '+' || arr[i][0] == '-')
			++j;
		while (arr[i][j])
		{
			if (ft_isdigit(arr[i][j]) == 0 && arr[i][j] != ' ')
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}
