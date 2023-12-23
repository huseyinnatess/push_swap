/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:30:36 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/23 20:34:20 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../libft/libft.h"

char	**ft_check_argv(int argc, char **argv, t_stacks *st)
{
	int	i;
	int	j;

	if (argc == 2)
	{
		i = -1;
		while (argv[1][++i])
			if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' '
				&& argv[1][i] != '-' && argv[1][i] != '+')
				ft_print_error(st, 1);
		return (ft_split(argv[1], ' '));
	}
	i = 1;
	while (i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j])
				&& argv[i][j] != '-' && argv[i][j] != '+')
				ft_print_error(st, 1);
		i++;
	}
	return (argv + 1);
}

void	ft_check_repeated_elements(t_stacks *st)
{
	int	i;
	int	j;

	i = 0;
	while (i < st->a_len)
	{
		j = 0;
		while (j < st->a_len)
		{
			if (st -> stack1[i] == st -> stack1[j] && i != j)
				ft_print_error(st, 1);
			j++;
		}
		i++;
	}
}

void	ft_check_min_max(char *str, t_stacks *st, char **params, int argc)
{
	long number;

	number = ft_atoi(str);
	if (number > 2147483647 || number < -2147483648)
	{
		ft_free_all_params(params, argc);
		ft_print_error(st, 1);
	}
}

int	ft_is_sorted(int a_len, int *stack_1)
{
	int	i;
	int	j;

	if (a_len == 0)
		return (0);
	i = 0;
	while (i < a_len - 1)
	{
		j = i + 1;
		while (j < a_len)
		{
			if (stack_1[i] < stack_1[j])
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
