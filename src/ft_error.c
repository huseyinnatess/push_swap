/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:30:18 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/23 20:30:32 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"
#include <stdlib.h>

void	ft_print_error(t_stacks *st, int check)
{
	if (st->a_len > 0)
		free(st -> stack1);
	if (st->b_len > 0)
		free(st -> stack2);
	if (check >= 0)
		free(st);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_free_all(t_stacks *st, int check)
{
	if (st->a_len > 0)
		free(st->stack1);
	if (st->b_len > 0)
		free(st->stack2);
	if (check >= 0)
		free(st);
	exit(0);
}
