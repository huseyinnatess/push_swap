/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduvan <fduvan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:28:53 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/07 18:33:46 by fduvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"

void	ra(t_stacks *st, int fl)
{
	int	temp;

	if (st -> a_len <= 1)
		return ;
	temp = st -> stack1[st->a_len - 1];
	ft_memmove(st -> stack1 + 1, st -> stack1, sizeof(int) * (st->a_len - 1));
	st -> stack1[0] = temp;
	if (fl)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stacks *st, int fl)
{
	int	temp;

	if (st -> b_len <= 1)
		return ;
	temp = st -> stack2[st->b_len - 1];
	ft_memmove(st -> stack2 + 1, st -> stack2, sizeof(int) * (st->b_len - 1));
	st -> stack2[0] = temp;
	if (fl)
		ft_putstr_fd("rb\n", 1);
}
