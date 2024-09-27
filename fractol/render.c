/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:03:52 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/27 14:41:17 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int cp)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iter == MAX_ITER)
		return (0x000000);
	t = sqrt((double)iter) / sqrt((double)MAX_ITER);
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	if (cp == 1)
		return ((r << 16) | (g << 8) | (b));
	if (cp == 2)
		return ((b << 16) | (g << 8) | (r));
	if (cp == 3)
		return ((r << 16) | (b << 8) | g);
	if (cp == 4)
		return (0xFFFF55 * t * (1 - t));
	return ((r << 16) | (g << 8) | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_data *img, t_complex c, int x, int y)
{
	int	res;
	int	color;

	if (img->fractal == 0)
		res = mandelbrot(c);
	else if (img->fractal == 1)
		res = julia(c, img->c_juila);
	else if (img->fractal == 2)
		res = multibrot(c, img->c_juila);
	else
		res = phoenix(*img, c);
	color = 0x00000000;
	if (res != MAX_ITER)
		color = get_color(res, img->color_palette);
	my_mlx_pixel_put(img, x, y, color);
}

void	print_fractal(t_data *img)
{
	int			x;
	int			y;
	t_complex	c;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c = calc_c(x, y, *img);
			draw(img, c, x, y);
			y++;
		}
		x++;
	}
}
