/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:03:49 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/12 17:13:58 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

void	move_aux(t_data *d, int keycode, double mov)
{
	t_complex	c;

	c.real = d->max_c.real - d->min_c.real;
	c.imaginary = d->max_c.imaginary - d->min_c.imaginary;
	if (keycode == K_UP)
	{
		d->min_c.imaginary += c.imaginary * mov;
		d->max_c.imaginary += c.imaginary * mov;
	}
	if (keycode == K_DOWN)
	{
		d->min_c.imaginary -= c.imaginary * mov;
		d->max_c.imaginary -= c.imaginary * mov;
	}
	if (keycode == K_RIGHT)
	{
		d->min_c.real += c.real * mov;
		d->max_c.real += c.real * mov;

	}
	if (keycode == K_LEFT)
	{
		d->min_c.real -= c.real * mov;
		d->max_c.real -= c.real * mov;
	}
}

int	move(int keycode, t_data *data)
{
	move_aux(data, keycode, 0.2);
	mlx_clear_window(data->mlx, data->win);
	print_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
