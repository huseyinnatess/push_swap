/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:04:00 by mcombeau          #+#    #+#             */
/*   Updated: 2023/12/21 14:46:16 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}


static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_len)
{
	if (stack_len == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_len == 3)
		tiny_sort(stack_a);
	else if (stack_len > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}


int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	stack_a->stack_len = ac - 1;
	assign_index(stack_a, stack_a->stack_len + 1);
	push_swap(&stack_a, &stack_b, stack_a->stack_len);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
