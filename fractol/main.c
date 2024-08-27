/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:15:43 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/08/27 17:47:54 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "fractol.h"


double	complex_abs(t_complex complex)
{
	double	r;

	r = sqrt(pow(complex.real, 2) + pow(complex.imaginary, 2));
	return (r);
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
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_complex	complex;

	complex.real = 3;
	complex.imaginary = 4;

	printf("%f", complex_abs(complex));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_circle(&img, 350, 500, 500, 0x00FFFF00);
	my_mlx_square(&img, 50, 50, 50, 0xFFFF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	double t = 20;

	while (t<110)
	{
		my_mlx_circle(&img, t*20, 1000 + cos(t)*20, 2, 0xFFFF0000);
		t += 0.1;
	}
	
	mlx_loop(mlx);
}
