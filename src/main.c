/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:16:23 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/23 21:19:17 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

static void	ft_sort_list(t_stacks *st)
{
	if (ft_is_sorted(st->a_len, st->stack1))
		ft_free_all(st, 2);
	else if (st->a_len == 2)
		sa(st);
	else if (st->a_len == 3)
		ft_sort_three_nums(st);
	else if (st->a_len <= 5)
		ft_sort_lower_nums(st);
	else
		ft_sort_stack(st);
}

int	main(int argc, char **argv)
{
	t_stacks	*stack_a;

	if (argc < 2)
		exit(0);
	stack_a = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stack_a)
		ft_print_error(stack_a, -1);
	else
	{
		create_stacks(stack_a, argc - 1);
		init_stacks(argc, argv, stack_a);
		ft_check_repeated_elements(stack_a);
		ft_sort_list(stack_a);
		ft_reverse_arr(stack_a->a_len, stack_a->stack1);
		yazdir(stack_a -> stack1, stack_a -> a_len);
		ft_free_all(stack_a, 2);
	}
	return (0);
}
