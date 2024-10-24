/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:13:12 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/24 20:39:55 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	int	aux;

	aux = data->stack_a[0].value;
	data->stack_a[0].value = data->stack_a[1].value;
	data->stack_a[1].value = aux;
	write(1, "sa\n", 3);
}

void	swap_b(t_data *data)
{
	int	aux;

	aux = data->stack_b[0].value;
	data->stack_b[0].value = data->stack_b[1].value;
	data->stack_b[1].value = aux;
	write(1, "sb\n", 3);
}

void	swap_s(t_data *data)
{
	swap_a(data);
	swap_b(data);
	write(1, "ss\n", 3);
}
