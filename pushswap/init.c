/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:49:10 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/01 19:58:39 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(int *a, int argc, char **arg)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		a[i - 1] = ft_atoi(arg[i]);
		i++;
	}
}

void	init_stacks(int *a, int *b, int argc, char **arg)
{
	a = ft_calloc(argc, sizeof(int));
	if (!a)
		free_mem(a);
	b = ft_calloc(argc, sizeof(int));
	if (!b)
	{
		free_mem(a);
		free_mem(b);
	}
	init_a(a, argc, arg);
}
