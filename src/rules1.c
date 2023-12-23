/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:53:15 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/23 20:16:32 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"

void	sa(t_stacks *st)
{
	int	temp;

	if (st -> a_len <= 1)
		return ;
	temp = st -> stack1[st -> a_len - 1];
	st -> stack1[st ->a_len - 1] = st -> stack1[st -> a_len - 2];
	st -> stack1[st -> a_len - 2] = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *st)
{
	int	temp;

	if (st -> b_len <= 1)
		return ;
	temp = st -> stack2[st->b_len - 1];
	st -> stack2[st->b_len - 1] = st -> stack2[st->b_len - 2];
	st -> stack2[st->b_len - 2] = temp;
	ft_putstr_fd("sb\n", 1);
}

void	pa(t_stacks *st)
{
	int	*new_a;
	int	*new_b;

	if (st->b_len == 0)
		return ;
	new_a = malloc(sizeof(int) * (st->a_len + 1));
	if (!new_a)
		ft_print_error(st, 2);
	ft_memcpy(new_a, st->stack1, sizeof(int) * st->a_len);
	new_a[st->a_len] = st->stack2[st->b_len - 1];
	if (st -> a_len > 0)
		free (st->stack1);
	st->stack1 = new_a;
	st->a_len++;
	st->b_len--;
	if (st->b_len == 0)
		free(st->stack2);
	else
	{
		new_b = malloc(sizeof(int) * (st->b_len));
		ft_memcpy(new_b, st->stack2, sizeof(int) * (st->b_len));
		free(st->stack2);
		st->stack2 = new_b;
	}
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stacks *st)
{
	int	*new_a;
	int	*new_b;

	if (st->a_len == 0)
		return ;
	new_b = malloc(sizeof(int) * (st->b_len + 1));
	if (!new_b)
		ft_print_error(st, 2);
	ft_memcpy(new_b, st->stack2, sizeof(int) * st->b_len);
	new_b[st->b_len] = st->stack1[st->a_len - 1];
	if (st->b_len > 0)
		free (st->stack2);
	st->stack2 = new_b;
	st->b_len++;
	st->a_len--;
	if (st->a_len == 0)
		free(st->stack1);
	else
	{
		new_a = malloc(sizeof(int) * (st->a_len));
		ft_memcpy(new_a, st->stack1, sizeof(int) * (st->a_len));
		free(st->stack1);
		st->stack1 = new_a;
	}
	ft_putstr_fd("pb\n", 1);
}
