/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:17:18 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/25 19:39:41 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data *data)
{
	t_number	n;

	n = pop(data->stack_b, data);
	append(data->stack_a, data, n);
	data->size_a++;
	data->size_b--;
	update_data(data);
	write(1, "pa\n", 3);
}

void	push_b(t_data *data)
{
	t_number	n;

	n = pop(data->stack_a, data);
	append(data->stack_b, data, n);
	data->size_a--;
	data->size_b++;
	update_data(data);
	write(1, "pb\n", 3);
}
