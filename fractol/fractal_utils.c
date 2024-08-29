/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:15:28 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/08/29 18:49:36 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	calc_c(int x, int y)
{
	t_complex	c;
	double		r_min;
	double		r_max;
	double		i_max;
	double		i_min;

	r_min = -2.0;
	r_max = 2.0;
	i_min = r_min * ((double)HEIGHT / (double)WIDTH);
	i_max = i_min + (r_max - r_min) * ((double)HEIGHT / (double)WIDTH);
	c.real = r_min + (x / (double)WIDTH) * (r_max - r_min);
	c.imaginary = i_max - (y / (double)HEIGHT) * (i_max - i_min);

	return (c);
}