/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduvan <fduvan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:30:36 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/06 14:43:12 by fduvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../libft/libft.h"

char	**ft_check_args(int arc, char **args, t_stacks *st)
{
	int	i;
	int	j;

	if (arc == 2)
	{
		i = -1;
		while (args[1][++i])
			if (!ft_isdigit(args[1][i]) && args[1][i] != ' '
				&& args[1][i] != '-' && args[1][i] != '+')
				ft_print_error(st, 1);
		return (ft_split(args[1], ' '));
	}
	i = 1;
	while (i < arc)
	{
		j = -1;
		while (args[i][++j])
			if (!ft_isdigit(args[i][j])
				&& args[i][j] != '-' && args[i][j] != '+')
				ft_print_error(st, 1);
		i++;
	}
	return (args + 1);
}

void	ft_check_repeated_elements(t_stacks *st)
{
	int	fl;
	int	i;
	int	j;

	i = 0;
	while (i < st->a_len)
	{
		j = 0;
		fl = 1;
		while (j < st->a_len)
		{
			if (st -> stack1[i] == st -> stack1[j] && i != j)
				ft_print_error(st, 1);
			j++;
		}
		i++;
	}
}

void	ft_check_min_max(char *str, t_stacks *st, char **params, int arc)
{
	int		sign;
	long	result;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result * sign > 2147483647 || result * sign < -2147483648)
	{
		ft_free_all_params(params, arc);
		ft_print_error(st, 1);
	}
}

int	ft_is_sorted(int arr_len, int *arr)
{
	int	i;
	int	j;

	if (arr_len == 0)
		return (0);
	i = 0;
	while (i < arr_len - 1)
	{
		j = i + 1;
		while (j < arr_len)
		{
			if (arr[i] < arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_decimal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}
