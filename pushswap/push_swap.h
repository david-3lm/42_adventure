/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:24 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/01 19:56:13 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"

void	free_mem(int *ptr);
void	push_swap(int *stack_a, int *stack_b);

/*INIT*/
void	init_a(int *a, int argc, char **arg);
void	init_stacks(int *a, int *b, int argc, char **arg);



#endif
