/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:49:10 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/14 10:40:37 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnumber(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	init_a(t_data *data, int argc, char **arg)
{
	int	i;
	int	n;

	i = 1;
	data->max = INT_MIN;
	data->min = INT_MAX;
	data->numbers = argc - 1;
	while (i < argc)
	{
		if (!ft_isnumber(arg[i]))
			return (FALSE);
		n = ft_atoi(arg[i]);
		data->stack_a[i - 1] = n;
		if (n > data->max)
			data->max = n;
		if (n < data->min)
			data->min = n;
		i++;
	}
	update_data(data);
	return (TRUE);
}
