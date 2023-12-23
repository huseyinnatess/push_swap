/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:28:40 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/23 21:12:04 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	create_stacks(t_stacks *st, int argc)
{
	st->stack1 = malloc(sizeof(int) * argc);
	if (st -> stack1 == NULL)
		ft_print_error(st, 0);
	st -> a_len = argc;
	st -> b_len = 0;
}

char	**ft_free_all_params(char **params, int argc)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (params[i])
		{
			free(params[i]);
			i++;
		}
		free(params);
	}
	return (NULL);
}

static void	ft_check_sign(char **params, t_stacks *st, int argc, int index)
{
	if (params[index][0] == '+' || params[index][0] == '-')
	{
		if (params[index][1] == '\0')
		{
			ft_free_all_params(params, argc);
			ft_print_error(st, 1);
		}
	}
}

static void	ft_is_valid_params(char **params, t_stacks *st, int argc)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (params[i])
	{
		j = 0;
		check = 0;
		ft_check_sign(params, st, argc, i);
		while (params[i][j])
		{
			if ((params[i][j] == '+' || params[i][j] == '-') && check == 1)
			{
				ft_free_all_params(params, argc);
				ft_print_error(st, 1);
			}
			if (params[i][j] == '+' || params[i][j] == '-'
				|| ft_isdigit(params[i][j]))
				check = 1;
			j++;
		}
		i++;
	}
}

void	init_stacks(int argc, char **argv, t_stacks *st)
{
	int		i;
	char	**params;

	params = ft_check_argv(argc, argv, st);
	ft_is_valid_params(params, st, argc);
	if (argc == 2)
	{
		free (st -> stack1);
		i = 0;
		while (params[i])
			i++;
		st -> stack1 = malloc(sizeof(int) * i);
	}
	i = 0;
	while (params[i])
	{
		ft_check_min_max(params[i], st, params, argc);
		st -> stack1[i] = ft_atoi(params[i]);
		i++;
	}
	st -> a_len = i;
	if (argc == 2)
		ft_free_all_params(params, argc);
	ft_reverse_arr(st->a_len, st->stack1);
}
