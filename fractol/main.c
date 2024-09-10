/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:15:43 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/10 20:06:40 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "fractol.h"
#include "keys.h"

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


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
			c = calc_c(x, y, *img);
			mandel = julia(c);
			color = 0x00000000;
			if (mandel != MAX_ITER)
				color = get_color(mandel);
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}
int	key_hook(int keycode, t_data *vars)
{
	int i;

	i = keycode;
	keycode = i;
	if (keycode == K_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == K_UP || keycode == K_LEFT || keycode == K_RIGHT || keycode == K_DOWN)
		move(keycode, vars);
	return (0);
}

int	close(int keycode, t_data *vars)
{
	(void)keycode;
	exit(0);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	create_limits(t_data *data)
{
	data->max_c.real = 4.0;
	data->min_c.real = -4.0;
	data->min_c.imaginary = -4.0;
	data->max_c.imaginary = data->min_c.imaginary + (data->max_c.real - data->min_c.real) * HEIGHT / WIDTH;
}

int	main(void)
{
	t_data		data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractalin");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	create_limits(&data);
	print_fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, hook_mouse, &data);
	mlx_hook(data.win, 17, 1L << 0, close, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	return (0);
}