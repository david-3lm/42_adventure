/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:03:52 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/29 20:14:31 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int cp, t_data data)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iter == data.iter)
		return (0x000000);
	t = sqrt((double)iter) / sqrt((double)data.iter);
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
		res = mandelbrot(c, *img);
	else if (img->fractal == 1)
		res = julia(c, *img);
	else if (img->fractal == 2)
		res = multibrot(c, *img);
	else
		res = phoenix(c, *img);
	color = 0x00000000;
	if (res != img->iter)
		color = get_color(res, img->color_palette, *img);
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
