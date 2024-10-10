/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/10 15:50:27 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_data *data)
{
	(void)data;
}

void	order_two(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[1])
		swap_a(data);
}


void	debug(t_data *data, int n)
{
	int	i;

	i = 0;
	ft_printf("_____size: %d_______\n", n);
	ft_printf("min: %d_______\n", data->min);
	ft_printf("max: %d_______\n", data->max);
	while (i < n)
	{
		ft_printf("%d\t%d\n", data->stack_a[i], data->stack_b[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		data.stack_a = ft_calloc(argc, sizeof(int));
		data.stack_b = ft_calloc(argc, sizeof(int));
		if (!data.stack_a || !data.stack_b)
			free_data(data);
		init_a(&data, argc, argv);
		if (argc == 3)
			order_two(&data);
		if (argc == 4)
			order_three(&data);
		else if (argc >= 5)
		{
			start_algo(&data);
		}
		//debug(&data, argc - 1);
		free_data(data);
	}
	return (0);
}
