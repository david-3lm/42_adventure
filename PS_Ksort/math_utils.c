/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:51:57 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/04 10:58:43 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_sqrt(int n)
{
	double	approx;
	double	better_approx;

	if (n < 0)
		return (-1);
	approx = n / 2.0;
	better_approx = 0.5 * (approx + n / approx);
	while (better_approx != approx)
	{
		approx = better_approx;
		better_approx = 0.5 * (approx + n / approx);
	}
	return (approx);
}

int	calc_k(t_data *data)
{
	int	k;

	k = ft_sqrt(data->numbers) * \
	((ft_sqrt(data->numbers) + data->numbers) / data->numbers);
	return (k);
}
