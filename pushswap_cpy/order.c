/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:59:14 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/25 18:19:36 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_two(t_data *data)
{
	if (data->stack_a[0].value > data->stack_a[1].value)
		swap_a(data);
}

void	order_three(t_data *data)
{
	int	order;

	order = check_order_asc(data);
	if (order == 0)
		return ;
	if (order == 1)
	{
		swap_a(data);
		order_three(data);
	}
	if (order == 2)
	{
		r_rotate_a(data);
		order_three(data);
	}
}

void	order_four(t_data *data)
{
	int	min_idx;

	min_idx = get_min_idx(data->stack_a, data->size_a);
	if (min_idx == 1)
		swap_a(data);
	else if (min_idx == 2)
	{
		rotate_a(data);
		swap_a(data);
	}
	else if (min_idx == 3)
		r_rotate_a(data);
	push_b(data);
	order_three(data);
	push_a(data);
}

void	order_five(t_data *data)
{
	int	min_idx;

	min_idx = get_min_idx(data->stack_a, data->size_a);
	if (min_idx == 1)
		swap_a(data);
	else if (min_idx == 2)
	{
		rotate_a(data);
		swap_a(data);
	}
	else if (min_idx == 3)
	{
		r_rotate_a(data);
		r_rotate_a(data);
	}
	else if (min_idx == 4)
		r_rotate_a(data);
	push_b(data);
	order_four(data);
	push_a(data);
}
