/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:16:59 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/02 16:45:26 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	r_rotate_a(int *stack_a)
{
	int n;

	n = pop_last(stack_a);
	append(stack_a, n);
}

void	r_rotate_b(int *stack_b)
{
	int n;

	n = pop_last(stack_b);
	append(stack_b, n);
}

void	r_rotate_s(int *stack_a, int *stack_b)
{
	r_rotate_a(stack_a);
	r_rotate_b(stack_b);
}