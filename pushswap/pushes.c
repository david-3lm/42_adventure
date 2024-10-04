/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:17:18 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/04 11:56:07 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(int *stack_a, int *stack_b)
{
	int	n;

	n = pop(stack_b);
	append(stack_a, n);
}

void	push_b(int *stack_a, int *stack_b)
{
	int	n;

	n = pop(stack_a);
	append(stack_b, n);
}
