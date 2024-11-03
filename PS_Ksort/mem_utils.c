/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:43:13 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/28 15:38:45 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}

void	free_mem(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

void	free_data(t_data *data)
{
    if (data->stack_a) {
        free(data->stack_a);
        data->stack_a = NULL;
    }
    if (data->stack_b) {
        free(data->stack_b);
        data->stack_b = NULL;
    }
}

void	free_pptr(char **ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		// if (ptr[i])
		// {
		// 	free(ptr[i]);
		// 	ptr[i] = NULL;
		// }
		i++;
	}
	free(ptr);
	ptr = NULL;
}

int	find_in_stack(t_number *stack, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n == stack[i].value)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
