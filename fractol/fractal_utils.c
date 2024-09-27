/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:15:28 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/27 16:47:55 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	calc_c(int x, int y, t_data data)
{
	t_complex	c;

	c.real = data.min_c.real + (double)x * \
		(data.max_c.real - data.min_c.real) / WIDTH;
	c.imaginary = data.max_c.imaginary + (double)y * \
		(data.min_c.imaginary - data.max_c.imaginary) / HEIGHT;
	return (c);
}

double	ft_atod(const char *nptr)
{
	double	integer_part;
	double	decimal_part;
	double	neg;
	double	divider;

	integer_part = 0;
	decimal_part = 0;
	neg = 1;
	divider = 1;
	if (*(nptr) == '-')
		neg = -1;
	while (ft_isdigit(*++nptr))
		integer_part = integer_part * 10 + (*nptr - '0');
	if (*nptr == '.')
	{
		while (ft_isdigit(*(++nptr)))
		{
			decimal_part = decimal_part * 10 + (*nptr - '0');
			divider *= 10;
		}
	}
	return (neg * (integer_part + (decimal_part / divider)));
}
