/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:11:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/09 17:26:36 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *d, double zoom)
{
	t_complex	c;

	c.real = d->min_c.real - d->max_c.real;
	c.imaginary = d->max_c.imaginary - d->min_c.imaginary;
	d->max_c.real += (c.real - zoom * c.real) / 2;
	d->min_c.real = d->max_c.real + zoom * c.real;
	d->min_c.imaginary += (c.imaginary - zoom * c.imaginary) / 2;
	d->max_c.imaginary = d->min_c.imaginary + zoom * c.imaginary;
}

int	hook_mouse(int keycode, int x, int y, t_data *data)
{
	x = y;
	y = x;
	if (keycode == 4)
	{
		//ZOOM IN
		zoom(data, 0.9);
	}
	if (keycode == 5)
	{
		//ZOOM OUT
		zoom(data, 1.1);
	}
	mlx_clear_window(data->mlx, data->win);
	print_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
