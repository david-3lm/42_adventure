/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:59:14 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/07 11:44:20 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_three(t_data *data)
{
	int	order;

	order = check_order_desc(data->stack_a);
	if (order == 0)
		return ;
	if (order == 1)
	{
		swap_a(data);
		order_three(data);
	}
	if (order == 2)
	{
		r_rotate_a(data);
		order_three(data);
	}
}
