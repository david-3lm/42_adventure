/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:17:04 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/28 11:50:47 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	t_number	n;

	n = pop(data->stack_a, data);
	data->size_a--;
	put_last(data->stack_a, data, n);
	data->size_a++;
	write(1, "ra\n", 3);
}

void	rotate_b(t_data *data)
{
	t_number	n;

	n = pop(data->stack_b, data);
	data->size_b--;
	put_last(data->stack_b, data, n);
	data->size_b++;
	write(1, "rb\n", 3);
}

void	rotate_s(t_data *data)
{
	t_number	n;

	n = pop(data->stack_a, data);
	data->size_a--;
	put_last(data->stack_a, data, n);
	data->size_a++;
	n = pop(data->stack_b, data);
	data->size_b--;
	put_last(data->stack_b, data, n);
	data->size_b++;
	write(1, "rr\n", 3);
}
