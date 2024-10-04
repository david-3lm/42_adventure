/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:24 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/04 15:14:40 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define EMPTY 0
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
	int	min;
	int	max;
	int	*stack_a;
	int	*stack_b;
}				t_data;

void	free_mem(int *ptr);
void	push_swap(int *stack_a, int *stack_b);

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
void	push_a(int *stack_a, int *stack_b);
void	push_b(int *stack_a, int *stack_b);
void	swap_a(int *stack_a);
void	swap_b(int *stack_b);
void	swap_s(int *stack_a, int *stack_b);
void	rotate_a(int *stack_a);
void	rotate_b(int *stack_b);
void	rotate_s(int *stack_a, int *stack_b);
void	r_rotate_a(int *stack_a);
void	r_rotate_b(int *stack_b);
void	r_rotate_s(int *stack_a, int *stack_b);

/*ORDER*/
int		check_order(int *s);
void	order_three(t_data *data);

#endif
