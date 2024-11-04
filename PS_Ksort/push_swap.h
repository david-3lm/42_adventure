/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:24 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/04 11:35:44 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define EMPTY 0
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define LONG_MIN -9223372036854775808
# define LONG_MAX 9223372036854775807
# define TRUE 1
# define FALSE 0
# include "libimp/libft.h"

typedef struct s_number
{
	int	value;
	int	idx;
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

void			update_data(t_data *data);

void			free_mem(void *ptr);
void			free_pptr(char **ptr);
void			free_data(t_data *data);
void			print_error(void);

/*INIT*/
int				init_a(t_data *a, int argc, char **arg);

/*UTILS*/
t_number		pop(t_number *stack, t_data *data);
t_number		pop_last(t_number *stack, t_data *data);
void			append(t_number *stack, t_data *data, t_number num);
void			put_last(t_number *stack, t_data *data, t_number num);
int				size(t_number *stack, t_data *data);
int				get_min_idx(t_number *stack, int size);
int				get_max_idx(t_number *stack, int size);
int				find_in_stack(t_number *stack, int n, int size);
int				calc_k(t_data *data);
double			ft_sqrt(int n);

/*MOVES*/
void			push_a(t_data *data);
void			push_b(t_data *data);
void			swap_a(t_data *data);
void			swap_b(t_data *data);
void			swap_s(t_data *data);
void			rotate_a(t_data *data);
void			rotate_b(t_data *data);
void			rotate_s(t_data *data);
void			r_rotate_a(t_data *data);
void			r_rotate_b(t_data *data);
void			r_rotate_s(t_data *data);

/*ORDER*/
int				check_order_desc(t_data *data);
int				check_order_asc(t_data *data);
void			order_two(t_data *data);
void			order_three(t_data *data);
void			order_four(t_data *data);
void			order_five(t_data *data);
int				get_correct_pos(int n, t_data *data);
int				get_correct_pos_b(int n, t_data *data);

/*ALGORYTHM*/
void			start_algo(t_data *data);
void			debug(t_data *data);

#endif
