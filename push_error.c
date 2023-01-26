/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_error.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:25:07 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/26 16:25:16 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*parse_num(int argc, char **argv)
{
	int		i;
	t_dlist	*lst;
	t_dlist	*new;

	lst = NULL;
	if (argc <= 1)
		return (printf("Error\n"), NULL);
	i = non_integer(argc, argv);
	if (i == 0)
		return (printf("Error\n"), NULL);
	if (argc == 1)
		lst = split_parse(argv[1]);
	while (i < argc)
	{
		new = dlstnew(ft_atoi(argv[i]));
		dlstadd_back(&lst, new);
		++i;
	}
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
	while (arr[i])
	{
		new = dlstnew(ft_atoi(arr[i]));
		dlstadd_back(&lst, new);
		free (arr[i]);
		++i;
	}
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
				return (printf("Error\n"), 0);
			pin = pin->next;
		}
		pon = pon->next;
		pin = pon->next;
	}
	pin = lst;
	while (pin)
	{
		if (pin->data > 2147483647
			|| pin->data < -2147483648)
			return (printf("Error\n"), 0);
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
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

void	free_list(t_dlist *lst)
{
	t_dlist	*ptr;

	ptr = lst->next;
	while (ptr)
	{
		free (lst);
		lst = ptr;
		ptr = lst->next;
	}
}

/*
error

1. MAX_INT

2. Duplicate
after parsing to stack a

3. Non-integer
ok
4. num list in string

-> atoi checks 





*/