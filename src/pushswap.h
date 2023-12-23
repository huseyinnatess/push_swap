/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:33:44 by fduvan            #+#    #+#             */
/*   Updated: 2023/12/23 20:34:03 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
typedef struct s_stacks
{
	int	*stack1;
	int	*stack2;
	int	a_len;
	int	b_len;
}	t_stacks;

void	ft_print_error(t_stacks *st, int pst);
void	ft_free_all(t_stacks *st, int fl);
char	**ft_free_all_params(char **result, int arc);

void	create_stacks(t_stacks *st, int el_count);
void	init_stacks(int arc, char **args, t_stacks *st);

int		*ft_reverse_arr(int arr_len, int *arr);
int		ft_min_num(int num1, int num2);

char	**ft_check_argv(int arc, char **args, t_stacks *st);
void	ft_check_repeated_elements(t_stacks *st);
void	ft_check_min_max(char *str, t_stacks *st, char **params, int arc);
int		ft_is_sorted(int arr_len, int *arr);
int		ft_is_decimal(char *str);
void	ft_is_full_whsp(int arc, char **params);

void	ft_sort_three_nums(t_stacks *st);
void	ft_sort_lower_nums(t_stacks *st);
void	ft_sort_stack(t_stacks *stacks);

int		ft_find_min_num_index(int arr_len, int *arr);
int		ft_find_corr_ind(int num, int arr_len, int *arr);

int		ft_abs(int num);

void	sa(t_stacks *st);
void	sb(t_stacks *st);
void	pa(t_stacks *st);
void	pb(t_stacks *st);
void	ra(t_stacks *st, int fl);
void	rb(t_stacks *st, int fl);
void	rra(t_stacks *st, int fl);
void	rrb(t_stacks *st, int fl);

#endif