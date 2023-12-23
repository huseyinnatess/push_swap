/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduvan <fduvan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:13:44 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/07 18:33:41 by fduvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"

void	rra(t_stacks *st, int fl)
{
	int	temp;
	int	i;

	if (st -> a_len <= 1)
		return ;
	i = 0;
	temp = st -> stack1[0];
	while (i < st -> a_len - 1)
	{
		st -> stack1[i] = st -> stack1[i + 1];
		i++;
	}
	st -> stack1[st->a_len - 1] = temp;
	if (fl)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stacks *st, int fl)
{
	int	temp;
	int	i;

	if (st -> b_len <= 1)
		return ;
	i = 0;
	temp = st -> stack2[0];
	while (i < st -> b_len - 1)
	{
		st -> stack2[i] = st -> stack2[i + 1];
		i++;
	}
	st -> stack2[st->b_len - 1] = temp;
	if (fl)
		ft_putstr_fd("rrb\n", 1);
}
