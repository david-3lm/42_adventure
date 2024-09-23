/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:15:43 by dlopez-l          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/17 18:46:17 by dlopez-l         ###   ########.fr       */
=======
/*   Updated: 2024/09/19 14:14:44 by dlopez-l         ###   ########.fr       */
>>>>>>> 3c77f5eb74c55ef09409d42ad7dfcd94025330cc
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "fractol.h"
#include "keys.h"

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
	else
		res = multibrot(c, img->c_juila);
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

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == K_UP || keycode == K_LEFT || keycode == K_RIGHT || keycode == K_DOWN)
		move(keycode, vars);
	else
	{
		if (keycode == K_TWO)
			vars->color_palette = 2;
		if (keycode == K_THREE)
			vars->color_palette = 3;
		if (keycode == K_ONE)
			vars->color_palette = 1;
		if (keycode == K_R)
			create_limits(vars);
		if (keycode == K_MINUS)
			zoom(vars, WIDTH / 2, HEIGHT / 2, 1.1);
		if (keycode == K_PLUS)
			zoom(vars, WIDTH / 2, HEIGHT / 2, 0.9);
		
		mlx_clear_window(vars->mlx, vars->win);
		print_fractal(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	}
	return (0);
}

int	close_win(int keycode, t_data *vars)
{
	(void)keycode;
	exit(0);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
int	frac_selected(char *arg)
{
	if (ft_strncmp(arg, "mandel", 7) == 0)
		return (0);
	if (ft_strncmp(arg, "julia", 7) == 0)
		return (1);
	if (ft_strncmp(arg, "multi", 7) == 0)
		return (2);
	return (-1);
}
// int	main(void)
// {
// 	t_complex c = {3.0, 2.0};
// 	t_complex res;

// 	res = complex_pow(c,4);
// 	printf("%f %f", res.real, res.imaginary);

// 	res = complex_pow2(c,4);
// 	printf("%f %f", res.real, res.imaginary);
	
// }

int	main(int argc, char **args)
{
	t_data		data;

	if (argc <= 1)
	{
		(void)args[0];
		invalid_input("Falta un fractal para ejecutar\n");
		return (0);
	}
	else
	{
		data.fractal = frac_selected(args[1]);
		if (data.fractal != -1)
		{
			if (data.fractal != 0 && argc >= 4)
			{
				data.c_juila.real = ft_atod(args[2]);
				data.c_juila.imaginary = ft_atod(args[3]);
			}
			data = init_mlx(data);
		}
		else
			invalid_input("Fractal no valido\n");
	}
	return (0);
}
