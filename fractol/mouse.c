/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:11:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/23 11:10:59 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *d, int x, int y, double zoom)
{
	t_complex	c;
	double		off_x;
	double		off_y;

	off_x = ((double)x / 800.0) - 0.5;
	off_y = ((double)y / 800.0) - 0.5;
	if (zoom > 1)
	{
		off_x = -off_x;
		off_y = -off_y;
	}
	ft_printf("%d, %d\n", x, y);
	c.real = d->min_c.real - d->max_c.real;
	c.imaginary = d->max_c.imaginary - d->min_c.imaginary;
	d->max_c.real += ((c.real - zoom * c.real) / 2) + off_x;
	d->min_c.real = d->max_c.real + zoom * c.real;
	d->min_c.imaginary += ((c.imaginary - zoom * c.imaginary) / 2) - off_y;
	d->max_c.imaginary = d->min_c.imaginary + zoom * c.imaginary;
}

int	hook_mouse(int keycode, int x, int y, t_data *data)
{
	x = y;
	y = x;
	if (keycode == 4)
	{
		//ZOOM IN
		zoom(data, x, y, 0.9);
	}
	else if (keycode == 5)
	{
		//ZOOM OUT
		zoom(data, x, y, 1.1);
	}
	mlx_clear_window(data->mlx, data->win);
	print_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

