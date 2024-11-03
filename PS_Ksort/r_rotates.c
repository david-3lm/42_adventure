/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:16:59 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/28 11:49:32 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_data *data)
{
	t_number	n;

	n = pop_last(data->stack_a, data);
	data->size_a--;
	append(data->stack_a, data, n);
	data->size_a++;
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_data *data)
{
	t_number	n;

	n = pop_last(data->stack_b, data);
	data->size_b--;
	append(data->stack_b, data, n);
	data->size_b++;
	write(1, "rrb\n", 4);
}

void	r_rotate_s(t_data *data)
{
	r_rotate_a(data);
	r_rotate_b(data);
	write(1, "rrr\n", 4);
}
