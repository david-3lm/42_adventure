/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:29:44 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/09 11:18:11 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void start_algo(t_data *data)
{
	int	idx;
	
	idx = 0;
	while (data->size_a > 3)
	{
		idx = get_correct_pos_b(data->stack_a[0], data);
		while (idx > 0)
		{
			rotate_b(data);
			idx--;
		}
		push_b(data);
		debug(data, data->numbers);
	}
	order_three(data);
	while (data->size_b != 0)
	{
		idx = get_correct_pos(data->stack_b[0], data);
		while (idx > 0)
		{
			rotate_a(data);
			idx--;
		}
		push_a(data);
	}
	while (data->stack_a[0] != data->min)
		rotate_a(data);
	
}
