/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:29:44 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/27 10:21:22 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

int	get_opt_step(t_data *data)
{
	int	aux;
	int	opt;
	int	i;

	i = 0;
	opt = INT_MAX;
	data->idx = 0;
	while (i < data->size_b)
	{
		aux = get_correct_pos(data->stack_b[i].value, data) + i;
		if (aux < opt)
		{
			if (aux > data->size_a / 2)
			{
				aux = data->size_a - aux;
				data->reverse = 1;
			}
			else
				data->reverse = 0;
			data->idx = i;
			opt = aux;
		}
		i++;
	}
	return (opt - data->idx);
}

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

void	start_algo(t_data *data)
{
	int	k;
	int	i;
	int	idx;

	i = 0;
	while (data->size_a > 5)
	{
		k = sqrt(data->stack_a[0].idx) * 1.33;
		if (data->stack_a[0].idx <= data->size_b)
			push_b(data);
		else if (data->stack_a[0].idx <= (data->size_b + k))
		{
			push_b(data);
			if (data->stack_a[0].idx > (data->size_b + sqrt(data->stack_a[0].idx) * 1.33))
				rotate_s(data);
			else
				rotate_b(data);
		}
		else
			rotate_a(data);
		i++;
	}
	order_five(data);
	while (data->size_b > 0)
	{
		max_to_top(data);
		data->reverse = 0;
		idx = get_correct_pos(data->stack_b[0].value, data);
		//idx = get_opt_step(data);
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
