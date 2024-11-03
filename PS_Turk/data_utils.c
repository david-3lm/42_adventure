/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:54:11 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/14 11:20:53 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	upd_a(t_data *data)
{
	int	i;

	i = 0;
	data->max_a = INT_MIN;
	data->min_a = INT_MAX;
	while (data->stack_a[i] != 0)
	{
		if (data->stack_a[i] > data->max_a)
			data->max_a = data->stack_a[i];
		if (data->stack_a[i] < data->min_a)
			data->min_a = data->stack_a[i];
		i++;
	}
	return (i);
}

int	upd_b(t_data *data)
{
	int	i;

	i = 0;
	data->max_b = INT_MIN;
	data->min_b = INT_MAX;
	while (data->stack_b[i] != 0)
	{
		if (data->stack_b[i] > data->max_b)
			data->max_b = data->stack_b[i];
		if (data->stack_b[i] < data->min_b)
			data->min_b = data->stack_b[i];
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
