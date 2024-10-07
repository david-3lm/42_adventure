/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:49:10 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/07 12:40:27 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(t_data *data, int argc, char **arg)
{
	int	i;
	int	n;

	i = 1;
	data->max = INT_MIN;
	data->min = INT_MAX;
	while (i < argc)
	{
		n = ft_atoi(arg[i]);
		data->stack_a[i - 1] = n;
		if (n > data->max)
			data->max = n;
		if (n < data->min)
			data->min = n;
		i++;
	}
	update_data(data);
}
