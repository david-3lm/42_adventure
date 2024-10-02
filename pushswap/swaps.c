/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:13:12 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/02 16:42:13 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_a(int *stack_a)
{
	int	aux;

	aux = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = aux;
}

void	swap_b(int *stack_b)
{
	int	aux;

	aux = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = aux;
}

void	swap_s(int *stack_a, int *stack_b)
{
	swap_a(stack_a, stack_b);
	swap_b(stack_a, stack_b);
}
