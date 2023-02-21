/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mod_lib.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 10:37:18 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/21 10:37:33 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	skip_index(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		++i;
	if (str[i] == '0')
		++i;
	if (str[i] == '+')
		++i;
	if (str[i] == '-')
		++i;
	return (i);
}

long long	ft_atolong(char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = skip_index(str);
	if (i > 1 && str[i - 1] == '-' && str[i - 2] == '+')
		return (0);
	num = 0;
	sign = 1;
	if (i > 0 && str[i - 1] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = 10 * num + (str[i] - 48);
			++i;
		}
		else
			break ;
	}
	if (num > 9223372036854775807
		|| (num == 922337203685477580 + 1 && sign < 0))
		return (1 * sign);
	return (num * sign);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}
