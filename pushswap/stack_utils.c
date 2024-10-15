/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:27:18 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/15 14:35:46 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(int *stack)
{
	int	num;
	int	i;

	num = stack[0];
	i = 0;
	while (stack[i + 1] != 0)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = 0;
	return (num);
}

void	append(int *stack, int num)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
		i++;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = num;
}

int	pop_last(int *stack)
{
	int	i;
	int	num;

	i = 0;
	while (stack[i + 1] != 0)
		i++;
	num = stack[i];
	stack[i] = 0;
	return (num);
}

void	put_last(int *stack, int num)
{
	int	i;

	i = 0;
	while (stack[i] != 0)
		i++;
	stack[i] = num;
}

int	size(int *stack)
{
	int	i;

	i = 0;
	while (stack[i] != '\0')
		i++;
	return (i);
}
