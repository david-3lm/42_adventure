/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:27:18 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/02 16:44:09 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pop(int *stack)
{
	int	num;
	int	i;

	num = stack[0];
	i = 0;
	while (stack[i + 1] != NULL)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = NULL;
	return (num);
}

void	append(int *stack, int num)
{
	int	i;
	
	i = 0;
	while (stack[i] != NULL)
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
	while (stack[i + 1] != NULL)
		i++;
	num = stack[i];
	stack[i] = NULL;
}

void	put_last(int *stack, int num)
{
	int	i;

	i = 0;
	while (stack[i] != NULL)
		i++;
	stack[i] = num;
}