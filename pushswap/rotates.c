/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:17:04 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/04 11:54:37 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *stack_a)
{
	int	n;

	n = pop(stack_a);
	put_last(stack_a, n);
}

void	rotate_b(int *stack_b)
{
	int	n;

	n = pop(stack_b);
	put_last(stack_b, n);
}

void	rotate_s(int *stack_a, int *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
