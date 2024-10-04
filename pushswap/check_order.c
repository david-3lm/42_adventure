/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:23:30 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/04 12:29:35 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns 0 if it is in order else returns the firs wrong number
int	check_order(int *s)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (s[i] > s[i + 1])
			return (i);
		i++;
	}
	return (0);
}
