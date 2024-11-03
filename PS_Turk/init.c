/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:49:10 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/22 18:17:08 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnumber(char *c)
{
	int	i;

	i = 0;
	if(c[i] == '-' || c[i] == '+')
		i++;
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

	data->max = INT_MIN;
	data->min = INT_MAX;
	data->numbers = argc;
	i = 0;
	while (i < argc)
	{
		if (ft_isnumber(arg[i]) == FALSE)
			return (FALSE);
		n = ft_atoi(arg[i]);
		if (find_in_stack(data->stack_a, n))
			return (FALSE);
		data->stack_a[i] = n;
		if (n > data->max)
			data->max = n;
		if (n < data->min)
			data->min = n;
		i++;
	}
	update_data(data);
	return (TRUE);
}
