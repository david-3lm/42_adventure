/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:24 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/07 12:15:07 by dlopez-l         ###   ########.fr       */
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

typedef struct s_data
{
	int	min;
	int	min_a;
	int	min_b;
	int	max;
	int	max_a;
	int	max_b;
	int	*stack_a;
	int	*stack_b;
	int	numbers;
	int	size_a;
	int size_b;
}				t_data;

void	update_data(t_data *data);

void	free_mem(int *ptr);
void	free_data(t_data data);
void	push_swap(t_data *data);

/*INIT*/
void	init_a(t_data *a, int argc, char **arg);
void	init_stacks(int *a, int *b, int argc, char **arg);

/*UTILS*/
int		pop(int *stack);
void	append(int *stack, int num);
int		pop_last(int *stack);
void	put_last(int *stack, int num);
int		size(int *stack);

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
int		check_order_desc(int *s);
int		check_order_asc(int *s);
void	order_three(t_data *data);
int		get_correct_pos(int n, t_data *data);

/*ALGORYTHM*/
void	start_algo(t_data *data);


#endif
