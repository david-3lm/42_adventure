/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:16:59 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/11 15:17:58 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_data *data)
{
	int	n;

	n = pop_last(data->stack_a);
	append(data->stack_a, n);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_data *data)
{
	int	n;

	n = pop_last(data->stack_b);
	append(data->stack_b, n);
	write(1, "rrb\n", 4);
}

void	r_rotate_s(t_data *data)
{
	int	n;

	n = pop_last(data->stack_a);
	append(data->stack_a, n);
	n = pop_last(data->stack_b);
	append(data->stack_b, n);
	write(1, "rrr\n", 4);
}
