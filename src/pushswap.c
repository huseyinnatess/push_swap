/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduvan <fduvan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:16:23 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/07 18:40:38 by fduvan           ###   ########.fr       */
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

int	main(int arc, char **args)
{
	t_stacks	*st_stacks;

	if (arc < 2)
		exit(0);
	ft_is_full_whsp(arc, args);
	st_stacks = malloc(sizeof(t_stacks));
	if (!st_stacks)
		ft_print_error(st_stacks, -1);
	else
	{
		create_stacks(st_stacks, arc - 1);
		init_stacks(arc, args, st_stacks);
		ft_check_repeated_elements(st_stacks);
		ft_sort_list(st_stacks);
		ft_free_all(st_stacks, 2);
	}
	return (0);
}
