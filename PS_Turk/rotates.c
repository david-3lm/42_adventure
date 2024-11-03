/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:17:04 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/10 15:05:16 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	int	n;

	n = pop(data->stack_a);
	put_last(data->stack_a, n);
	write(1, "ra\n", 3);
}

void	rotate_b(t_data *data)
{
	int	n;

	n = pop(data->stack_b);
	put_last(data->stack_b, n);
	write(1, "rb\n", 3);
}

void	rotate_s(t_data *data)
{
	int	n;

	n = pop(data->stack_a);
	put_last(data->stack_a, n);
	n = pop(data->stack_b);
	put_last(data->stack_b, n);
	write(1, "rr\n", 3);
}
