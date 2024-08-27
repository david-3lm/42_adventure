/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:15:43 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/08/27 21:01:23 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "fractol.h"

int	mandelbrot(t_complex c)
{
	int			i;
	t_complex	z;

	z.imaginary = 0;
	z.real = 0;
	i = 0;
	while (complex_abs(z) <= 2 && i < MAX_ITER)
	{
		z = complex_add(complex_mult(z, z), c);
		i++;
	}
	return (i);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	my_mlx_square(t_data *data, int x, int y, int size, int color)
{
    int	i;
    int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	my_mlx_circle(t_data *data, int x, int y, int radius, int color)
{
	int i;
	int j;

	j = -radius;
	while (j <= radius)
	{
		i = -radius;
		while (i <= radius)
		{
			if ((i * i) + (j * j) <= (radius * radius))
			{
				my_mlx_pixel_put(data, i + x, j + y, color);
			}
			i++;
		}
		j++;
	}
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	//coords
	int			x;
	int			y;
	t_complex	c;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 0;
	while (x < 1920)
	{
		y = 0;
		while (y < 1080)
		{
			c.real = (x - 1920 / 2.0) * 4.0 / 1920;
			c.imaginary = (y - 1080 / 2.0) * 4.0 / 1080;
			if (mandelbrot(c) == MAX_ITER)
				my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			else
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			y++;
		}
		x++;
	}
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
}
