/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:15:43 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/08/29 20:48:39 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "fractol.h"

int get_color(int iter)
{
    if (iter == MAX_ITER)
        return 0x000000; // Negro para puntos dentro del conjunto

    double t = (double)iter / MAX_ITER; // Escala el número de iteraciones.
    int r = (int)(9 * (1 - t) * t * t * t * 255); // Componente roja
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255); // Componente verde
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); // Componente azul
    return (r << 16) | (g << 8) | b; // Combina los componentes en un color RGB.
}


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

void	print_fractal(t_data *img)
{
	int			x;
	int			y;
	t_complex	c;
	int			mandel;
	int			color;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c = calc_c(x, y);
			mandel = mandelbrot(c);
			color = 0x00000000;
			if (mandel != MAX_ITER)
				color = get_color(mandel);
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}
int	close(int keycode, t_data *vars)
{
	int i;

	i = keycode;
	keycode = i;
	if (keycode == K_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_data		data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractalin");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	print_fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 1L<<0, close, &data);
	mlx_mouse_hook(data.win, hook_mouse, &data);

	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	return (0);
}
