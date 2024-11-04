/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:29:44 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/04 11:00:10 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	max_to_top(t_data *data)
{
	int	i;

	i = 0;
	data->reverse = 0;
	while (data->stack_b[i].value != data->max_b)
		i++;
	if (i > data->size_b / 2)
	{
		i = data->size_b - i;
		data->reverse = 1;
	}
	while (i > 0)
	{
		if (data->reverse)
			r_rotate_b(data);
		else
			rotate_b(data);
		i--;
	}
}

void	min_to_top(t_data *data)
{
	int	i;

	i = 0;
	data->reverse = 0;
	while (data->stack_a[i].value != data->min_a)
		i++;
	if (i > data->size_a / 2)
	{
		i = data->size_a - i;
		data->reverse = 1;
	}
	while (i > 0)
	{
		if (data->reverse)
			r_rotate_a(data);
		else
			rotate_a(data);
		i--;
	}
}

void	last_step(t_data *data)
{
	int	idx;

	while (data->size_b > 0)
	{
		max_to_top(data);
		data->reverse = 0;
		idx = get_correct_pos(data->stack_b[0].value, data);
		if (idx > data->size_a / 2)
		{
			idx = data->size_a - idx;
			data->reverse = 1;
		}
		while (idx > 0)
		{
			if (data->reverse)
				r_rotate_a(data);
			else
				rotate_a(data);
			idx--;
		}
		push_a(data);
	}
	min_to_top(data);
}

void	start_algo(t_data *data)
{
	int	k;
	int	i;

	i = 0;
	while (data->size_a > 5)
	{
		k = calc_k(data);
		if (data->stack_a[0].idx <= data->size_b)
			push_b(data);
		else if (data->stack_a[0].idx <= (data->size_b + k))
		{
			push_b(data);
			if (data->stack_a[0].idx > (data->size_b + calc_k(data)))
				rotate_s(data);
			else
				rotate_b(data);
		}
		else
			rotate_a(data);
		i++;
	}
	order_five(data);
	last_step(data);
}
