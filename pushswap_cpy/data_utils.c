/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:54:11 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/24 20:34:48 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	upd_a(t_data *data)
{
	int	i;
	int	s;

	i = 0;
	data->max_a = INT_MIN;
	data->min_a = INT_MAX;
	s = size(data->stack_a);
	while (i < s)
	{
		if (data->stack_a[i].value > data->max_a)
			data->max_a = data->stack_a[i].value;
		if (data->stack_a[i].value < data->min_a)
			data->min_a = data->stack_a[i].value;
		i++;
	}
	return (i);
}

int	upd_b(t_data *data)
{
	int	i;
	int	s;

	i = 0;
	data->max_b = INT_MIN;
	data->min_b = INT_MAX;
	s = size(data->stack_b);
	while (i < s)
	{
		if (data->stack_b[i].value > data->max_b)
			data->max_b = data->stack_b[i].value;
		if (data->stack_b[i].value < data->min_b)
			data->min_b = data->stack_b[i].value;
		i++;
	}
	return (i);
}

void	update_data(t_data *data)
{
	data->size_a = upd_a(data);
	data->size_b = upd_b(data);
	data->median = (data->max - data->min) / 2;
}
