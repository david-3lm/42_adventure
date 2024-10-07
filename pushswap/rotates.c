/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:17:04 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/07 11:43:25 by dlopez-l         ###   ########.fr       */
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
	rotate_a(data);
	rotate_b(data);
	write(1, "rr\n", 3);
}
