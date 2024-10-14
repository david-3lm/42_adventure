/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:43:13 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/14 11:21:09 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	free_mem(int *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_data(t_data data)
{
	free(data.stack_a);
	data.stack_a = NULL;
	free(data.stack_b);
	data.stack_b = NULL;
}
