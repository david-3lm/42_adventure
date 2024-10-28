/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:27:18 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/28 11:57:43 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	pop(t_number *stack, t_data *data)
{
	t_number	num;
	int			i;
	int			s;

	num = stack[0];
	i = 0;
	s = size(stack, data);
	while (i < s - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = (t_number){0, 0};
	return (num);
}

void	append(t_number *stack, t_data *data, t_number num)
{
	int	i;
	int	s;

	s = size(stack, data);
	if (s != 0)
	{
		i = s;
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
	}
	stack[0] = num;
}

t_number	pop_last(t_number *stack, t_data *data)
{
	t_number	num;
	int			i;
	int			s;

	s = size(stack, data);
	i = 0;
	while (i < s - 1)
		i++;
	num = stack[i];
	stack[i] = (t_number){0, 0};
	return (num);
}

void	put_last(t_number *stack, t_data *data, t_number num)
{
	int	i;
	int	s;

	s = size(stack, data);
	i = 0;
	i = s;
	stack[i] = num;
}

int	size(t_number *stack, t_data *data)
{
	if (stack == data->stack_a)
		return (data->size_a);
	return (data->size_b);
}
