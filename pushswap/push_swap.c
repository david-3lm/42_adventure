/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/04 12:59:34 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int *stack_b)
{
	(void)stack_a;
	(void)stack_b;
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
		if (!data.stack_a)
			free_mem(data.stack_a);
		data.stack_b = ft_calloc(argc, sizeof(int));
		if (!data.stack_b)
		{
			free_mem(data.stack_a);
			free_mem(data.stack_b);
		}
		init_a(&data, argc, argv);
		if (check_order(data.stack_a) == 0)
			debug(&data, argc - 1);
	}
	return (0);
}
