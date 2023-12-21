/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:32:10 by mcombeau          #+#    #+#             */
/*   Updated: 2023/12/21 20:47:09 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void yazdir(t_stack **stack_a)
{
	t_stack *temp;
	int a_size;
	int i;

	i = 0;
	temp = *stack_a;
	a_size = get_stack_size(*stack_a);
	while (i < a_size)
	{
		printf("%d ", temp->value);
		temp = temp->next;
		i++;
	}
	printf("\n");
}

int ABS(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

int find_target_index(t_stack **stack_a, t_stack **stack_b, int a_size)
{
	int i;
	int target_index;
	int count;
	int tmp;

	i = 1;
	target_index = 1;
	count = ABS((*stack_b) -> value - (*stack_a) -> value);
	while (i <= a_size && (*stack_b) -> next != NULL)
	{
		i++;
		(*stack_b) = (*stack_b)->next;
		tmp = ABS((*stack_b) -> value - (*stack_a)->value);
		if (tmp < count)
		{
			count = tmp;
			target_index = i;
		}
	}
	return (target_index);
}

void ft_calculate(t_stack **stack_a, t_stack **stack_b, int b_size)
{
	int target_index;
	int left_step;
	int right_step;
	t_stack *temp;

	temp = *stack_b;
	target_index = find_target_index(stack_a, stack_b, b_size);
	left_step = target_index;
	right_step = b_size - target_index;

	if (left_step <= right_step)
	{
		while (left_step > 0)
		{
			do_rb(stack_b);
			left_step--;
		}
	}
	else
	{
		while (right_step > 0)
		{
			do_rrb(stack_b);
			right_step--;
		}
		do_pb(stack_a, stack_b);
		left_step = right_step + 1;
		while (left_step > 0)
		{
			do_rb(stack_b);
			left_step--;
		}
	}
}


void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int a_size;
	int b_size;
	t_stack *temp;

	i = 0;
	b_size = 0;
	a_size = get_stack_size(*stack_a);
	while (i < 2 && a_size > 2)
	{
		do_pb(stack_a, stack_b);
		a_size--;
		b_size++;
		i++;
	}
	if (is_sorted(*stack_b))
		do_sa(stack_b);
	
	
	temp = *stack_b;
	ft_calculate(stack_a, stack_b, b_size);
	stack_b = &temp;
	ft_calculate(stack_a, stack_b, b_size + 1);
	yazdir(stack_b);
}
