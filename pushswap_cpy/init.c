/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:49:10 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/25 16:39:12 by dlopez-l         ###   ########.fr       */
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
int	get_lower_nbr(t_data *data, int vaule)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < data->size_a)
	{
		if (vaule > data->stack_a[i].value)
			n++;
		i++;
	}
	return (n);
}

void	init_index(t_data *data)
{
	int	i;
	int	s;

	i = 0;
	s = data->size_a;
	while (i < s)
	{
		data->stack_a[i].idx = get_lower_nbr(data, data->stack_a[i].value);
		i++;
	}
}

int	init_a(t_data *data, int argc, char **arg)
{
	int	i;
	int	n;

	data->max = INT_MIN;
	data->min = INT_MAX;
	data->numbers = argc;
	data->size_a = data->numbers;
	data->size_b = 0;
	i = 0;
	while (i < argc)
	{
		if (ft_isnumber(arg[i]) == FALSE)
			return (FALSE);
		n = ft_atoi(arg[i]);
		if (find_in_stack(data->stack_a, n, i))
			return (FALSE);
		data->stack_a[i].value = n;
		if (n > data->max)
			data->max = n;
		if (n < data->min)
			data->min = n;
		i++;
	}
	init_index(data);
	update_data(data);
	return (TRUE);
}
