/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:03:49 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/29 20:30:42 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

void	move(int keycode, t_data *d, double mov)
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

void	key_color(int keycode, t_data *vars)
{
	if (keycode == K_ONE)
		vars->color_palette = 1;
	if (keycode == K_TWO)
		vars->color_palette = 2;
	if (keycode == K_THREE)
		vars->color_palette = 3;
	if (keycode == K_FOUR)
		vars->color_palette = 4;
}

void	key_zoom(int keycode, t_data *vars)
{
	if (keycode == K_R)
		create_limits(vars);
	if (keycode == K_MINUS)
		zoom(vars, WIDTH / 2, HEIGHT / 2, 1.1);
	if (keycode == K_PLUS)
		zoom(vars, WIDTH / 2, HEIGHT / 2, 0.9);
}

void	key_iter(int keycode, t_data *vars)
{
	if (keycode == K_G)
		vars->iter += 10;
	else if (keycode == K_B)
		vars->iter -= 10;
}
