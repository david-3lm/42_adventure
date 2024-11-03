/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:06:50 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/11 12:17:03 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_idx(int *stack, int size)
{
	int	i;
	int	min;
	int	idx;

	i = 0;
	min = INT_MAX;
	idx = 0;
	while (i < size)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

int	get_max_idx(int *stack, int size)
{
	int	i;
	int	max;
	int	idx;

	i = 0;
	max = INT_MIN;
	idx = 0;
	while (i < size)
	{
		if (stack[i] > max)
		{
			max = stack[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}
