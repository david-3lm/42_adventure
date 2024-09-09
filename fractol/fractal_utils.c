/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:15:28 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/09 12:39:29 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	calc_c(int x, int y, t_data data)
{
	t_complex	c;
	double		r_min;
	double		r_max;
	double		i_max;
	double		i_min;

	r_min = -2.0 + data.zoom;
	r_max = 2.0  - data.zoom;
	i_min = r_min * ((double)HEIGHT / (double)WIDTH);
	i_max = i_min + (r_max - r_min) * ((double)HEIGHT / (double)WIDTH);
	c.real = r_min + (x / (double)WIDTH) * (r_max - r_min) + data.off_x;
	c.imaginary = i_max - (y / (double)HEIGHT) * (i_max - i_min) + data.off_y;

	return (c);
}