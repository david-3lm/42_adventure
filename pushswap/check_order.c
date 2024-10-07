/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:23:30 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/07 12:54:50 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns 0 if it is in order else returns the first wrong number
int	check_order_desc(int *s)
{
	int	i;

	i = 0;
	while (i < size(s) - 1)
	{
		if (s[i] > s[i + 1])
		{
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int	check_order_asc(int *s)
{
	int	i;

	i = 0;
	while (i < size(s) - 1)
	{
		if (s[i] < s[i + 1])
		{
			return (i + 1);
		}
		i++;
	}
	return (0);
}

int	get_correct_pos(int n, t_data *data)
{
	int	i;
	int	s;

	i = 0;
	s = size(data->stack_a);
	if (n < data->stack_a[i] && n > data->stack_a[s - 1])
		return (0);
	while (i < s)
	{
		if (data->stack_a[i] < n && n < data->stack_a[i + 1])
			return (i + 1);
		if (n < data->min_a && data->stack_a[i] == data->min_a)
			return (i);
		if (n > data->max_a && data->stack_a[i] == data->max_a)
			return (i + 1);
		i++;
	}
	if (data->stack_a[s - 1] < n)
		return (0);
	return (0);
}