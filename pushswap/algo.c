/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:29:44 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/14 11:20:35 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_opt_step(t_data *data)
{
	int	aux;
	int	opt;
	int	i;

	i = 0;
	opt = INT_MAX;
	data->idx = 0;
	while (i < data->size_a)
	{
		aux = get_correct_pos_b(data->stack_a[i], data) + i;
		if (aux < opt)
		{
			if (aux > data->size_b / 2)
			{
				aux = data->size_b - aux;
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
	while (data->stack_b[i] != data->max_b)
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
	while (data->stack_a[i] != data->min_a)
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
	int	idx;

	idx = 0;
	while (data->size_a > 5)
	{
		data->reverse = 0;
		idx = get_opt_step(data);
		while (idx > 0 || data->idx > 0)
		{
			if (data->idx > 0 && idx > 0 && !data->reverse)
				rotate_s(data);
			else if (data->idx > 0)
			{
				rotate_a(data);
			}
			else if (data->reverse)
				r_rotate_b(data);
			else
				rotate_b(data);
			data->idx--;
			idx--;
		}
		push_b(data);
	}
	order_five(data);
	if (data->size_b != 0)
		max_to_top(data);
	while (data->size_b != 0)
	{
		data->reverse = 0;
		idx = get_correct_pos(data->stack_b[0], data);
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
