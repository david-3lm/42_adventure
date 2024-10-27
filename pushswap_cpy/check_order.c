/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:23:30 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/27 10:09:20 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns 0 if it is in order else returns the first wrong number
int	check_order_desc(t_data *data)
{
	int	i;
	int	s;

	i = 0;
	s = data->size_b;
	while (i < s - 1)
	{
		if (data->stack_b[i].value < data->stack_b[i + 1].value)
		{
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int	check_order_asc(t_data *data)
{
	int	i;
	int	s;

	i = 0;
	s = data->size_a;
	while (i < s)
	{
		if (data->stack_a[i].value > data->stack_a[i + 1].value)
		{
			return (i + 1);
		}
		i++;
	}
	return (0);
}
void debug(t_data *data)
{
	int i = 0;

	while (i < data->size_a)
	{
		i++;
	}
	
}

int	get_correct_pos(int n, t_data *data)
{
	int	i;
	int	s;

	i = 0;
	s = data->size_a;
	if (n < data->stack_a[i].value && n > data->stack_a[s - 1].value)
		return (0);
	if (n < data->min_a)
		return (get_min_idx(data->stack_a, data->size_a));
	if (n > data->max_a)
		return (get_max_idx(data->stack_a, data->size_a) + 1);
	while (i < s - 1)
	{
		if (data->stack_a[i].value < n && n < data->stack_a[i + 1].value)
			return (i + 1);
		i++;
	}
	if (data->stack_a[s - 1].value < n)
		return (0);
	return (0);
}

int	get_correct_pos_b(int n, t_data *data)
{
	int	i;
	int	s;

	i = 0;
	s = data->size_b;
	if (s == 0)
		return (0);
	if (n > data->stack_b[i].value && n < data->stack_b[s - 1].value)
		return (0);
	while (i < s - 1)
	{
		if (data->stack_b[i].value > n && n > data->stack_b[i + 1].value)
			return (i + 1);
		if (n < data->min_b && data->stack_b[i].value == data->min_b)
			return (i + 1);
		if (n > data->max_b && data->stack_b[i].value == data->max_b)
			return (i);
		i++;
	}
	if (data->stack_b[s - 1].value > n)
		return (0);
	return (0);
}
