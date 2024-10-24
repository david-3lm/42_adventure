/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:24 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/24 20:43:56 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define EMPTY 0
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define TRUE 1
# define FALSE 0
# include "ft_printf/ft_printf.h"

typedef struct s_number
{
	int	idx;
	int	value;
}				t_number;

typedef struct s_data
{
	t_number	*stack_a;
	t_number	*stack_b;
	int			min;
	int			min_a;
	int			min_b;
	int			max;
	int			max_a;
	int			max_b;
	int			numbers;
	int			size_a;
	int			size_b;
	int			reverse;
	int			idx;
	int			median;
}				t_data;

void	update_data(t_data *data);

void	free_mem(int *ptr);
void	free_data(t_data data);
void	push_swap(t_data *data);
void	print_error(void);

/*INIT*/
int		init_a(t_data *a, int argc, char **arg);
void	init_stacks(int *a, int *b, int argc, char **arg);

/*UTILS*/
int		pop(t_number *stack);
void	append(t_number *stack, int num);
int		pop_last(t_number *stack);
void	put_last(t_number *stack, int num);
int		size(t_number *stack);
int		get_min_idx(t_number *stack, int size);
int		get_max_idx(t_number *stack, int size);
int		find_in_stack(t_number *stack, int n);


/*MOVES*/
void	push_a(t_data *data);
void	push_b(t_data *data);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_s(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_s(t_data *data);
void	r_rotate_a(t_data *data);
void	r_rotate_b(t_data *data);
void	r_rotate_s(t_data *data);

/*ORDER*/
int		check_order_desc(t_number *s);
int		check_order_asc(t_number *s);
void	order_two(t_data *data);
void	order_three(t_data *data);
void	order_four(t_data *data);
void	order_five(t_data *data);
int		get_correct_pos(int n, t_data *data);
int		get_correct_pos_b(int n, t_data *data);

/*ALGORYTHM*/
void	start_algo(t_data *data);

#endif
