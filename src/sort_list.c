/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:16:07 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/22 18:07:31 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

#include <stdio.h>

void yazdir(int *array, int len)
{
	int i;
	int lentmp;

	lentmp = len;
	i = 0;
	while (i < len)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("Len: %d", lentmp);
	printf("\n");
}

void	ft_sort_three_nums(t_stacks *st)
{
	if (ft_is_sorted(st->a_len, st->stack1))
		return ;
	if (st->stack1[2] > st->stack1[1] && st->stack1[1] < st->stack1[0]
		&& st->stack1[2] < st->stack1[0])
		sa(st);
	else if (st->stack1[2] > st->stack1[1] && st->stack1[1] > st->stack1[0])
	{
		sa(st);
		rra(st, 1);
	}
	else if (st->stack1[2] > st->stack1[1] && st->stack1[1] < st->stack1[0]
		&& st->stack1[2] > st->stack1[0])
		ra(st, 1);
	else if (st->stack1[2] < st->stack1[1] && st->stack1[2] < st->stack1[0]
		&& st->stack1[1] > st->stack1[0])
	{
		sa(st);
		ra(st, 1);
	}
	else if (st -> stack1[2] < st->stack1[1] && st->stack1[2] > st->stack1[0]
		&& st->stack1[1] > st->stack1[0])
		rra(st, 1);
}

static void	ft_push_b(t_stacks *st, int step_a, int step_b)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (step_a < 0)
		while (++i < ft_abs(step_a))
			rra(st, 1);
	else if (step_a > 0)
		while (++i < ft_abs(step_a))
			ra(st, 1);
	if (step_b < 0)
		while (++j < ft_abs(step_b))
			rrb(st, 1);
	else if (step_b > 0)
		while (++j < ft_abs(step_b))
			rb(st, 1);
	pb(st);
}

int	ft_find_corr_ind(int value, int stack_2_len, int *stack_2)
{
	int		i;
	int		target_index;
	long	min_step;

	i = 0;
	target_index = 0;
	min_step = 2147483648 * 2;
	while (i < stack_2_len)
	{
		if (min_step > ft_abs(stack_2[i] - value))
		{
			target_index = i;
			min_step = ft_abs(stack_2[i] - value);
		}
		i++;
	}
	return (target_index);
}

static void	ft_push_min_step_b(t_stacks *st, int i, int j)
{
	long	min_step_count;
	int		total_step_count;
	int		step_a_count;
	int		step_b_count;

	min_step_count = 2147483648 * 2;
	i = st->a_len - 1; 
	while (st->a_len > 0 && i >= 0)
	{
		j = ft_find_corr_ind(st->stack1[i], st->b_len, st->stack2);
		total_step_count = ft_abs(ft_min_num(st->a_len - i - 1, -i - 1)); // ilk parametre soldan başa hamle sayısı, ikinci parametre sağdan başa hamle sayısı
		total_step_count += ft_abs(ft_min_num(st->b_len - j - 1, -j - 1));
		if (min_step_count > total_step_count)
		{
			step_a_count = ft_min_num(st->a_len - i - 1, -i - 1);
			step_b_count = ft_min_num(st->b_len - j - 1, -j - 1);
			min_step_count = total_step_count;
			if (st->stack1[i] < st->stack2[j])
				step_b_count++;
		}
		i--;
	}
	ft_push_b(st, step_a_count, step_b_count);
}

void	ft_sort_stack(t_stacks *st)
{
	int	i;
	int	rev_b_count;

	i = 0;
	while (st->a_len > 2 && i < 2)
	{
		pb(st);
		i++;
	}
	while (st->a_len > 0)
		ft_push_min_step_b(st, 0, 0);
	i = -1;
	rev_b_count = ft_find_min_num_index(st->b_len, st->stack2);
	while (++i < rev_b_count)
		rrb(st, 1);
	while (st->b_len > 0)
		pa(st);
}
