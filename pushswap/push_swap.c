/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:32:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/01 20:02:43 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int *stack_b)
{
	(void)stack_a;
	(void)stack_b;
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	if (argc > 1)
	{
		stack_a = ft_calloc(argc, sizeof(int));
		if (!stack_a)
			free_mem(stack_a);
		stack_b = ft_calloc(argc, sizeof(int));
		if (!stack_b)
		{
			free_mem(stack_a);
			free_mem(stack_b);
		}
		init_a(stack_a, argc, argv);
	}
	return (0);
}
