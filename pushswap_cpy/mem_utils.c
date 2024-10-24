/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:43:13 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/24 20:30:06 by dlopez-l         ###   ########.fr       */
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

int	find_in_stack(t_number *stack, int n)
{
	int	i;

	i = 0;
	while (i < size(stack))
	{
		if (n == stack[i].value)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
