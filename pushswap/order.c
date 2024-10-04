/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:59:14 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/04 15:08:29 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_three(t_data *data)
{
	int	order;

	order = check_order(data->stack_a);
	if (order == 0)
		return ;
	if (order == 1)
	{
		swap_a(data->stack_a);
		order_three(data);
	}
	if (order == 2)
	{
		r_rotate_a(data->stack_a);
		order_three(data);
	}
}
