/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:17:18 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/07 12:02:54 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data *data)
{
	int	n;

	n = pop(data->stack_b);
	append(data->stack_a, n);
	update_data(data);
	write(1, "pa\n", 3);
}

void	push_b(t_data *data)
{
	int	n;

	n = pop(data->stack_a);
	append(data->stack_b, n);
	update_data(data);
	write(1, "pb\n", 3);
}
