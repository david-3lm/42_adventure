/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:27:18 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/24 20:38:46 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_number *stack)
{
	int	num;
	int	i;
	int	s;

	num = stack[0].value;
	i = 0;
	s = size(stack);
	while (i < s)
	{
		stack[i].value = stack[i + 1].value;
		i++;
	}
	stack[i].value = 0;
	return (num);
}

void	append(t_number *stack, int num)
{
	int	i;
	int	s;

	i = 0;
	s = size(stack);
	while (i < s - 1)
		i++;
	while (i > 0)
	{
		stack[i].value = stack[i - 1].value;
		i--;
	}
	stack[0].value = num;
}

int	pop_last(t_number *stack)
{
	int	i;
	int	num;
	int	s;

	i = 0;
	s = size(stack);
	while (i < s)
		i++;
	num = stack[i].value;
	stack[i].value = 0;
	return (num);
}

void	put_last(t_number *stack, int num)
{
	int	i;
	int	s;

	i = 0;
	s = size(stack);
	while (i < s - 1)
		i++;
	stack[i].value = num;
}

int	size(t_number *stack)
{
	int	i;

	i = 0;
	while (&stack[i] != (t_number *)NULL)
		i++;
	return (i);
}
