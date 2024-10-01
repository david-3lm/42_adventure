/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:15:43 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/01 10:52:49 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "fractol.h"
#include "keys.h"

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == K_ESC)
	{
		//mlx_destroy_window(vars->mlx, vars->win);
		// exit(0);
		close_win(0, vars);
	}
	else if (keycode == K_UP || keycode == K_LEFT \
		|| keycode == K_RIGHT || keycode == K_DOWN)
		move(keycode, vars, 0.2);
	else
	{
		key_color(keycode, vars);
		key_zoom(keycode, vars);
		key_iter(keycode, vars);
	}
	mlx_clear_window(vars->mlx, vars->win);
	print_fractal(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
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
	if (ft_strncmp(arg, "phoenix", 10) == 0)
		return (3);
	return (-1);
}

int	main(int argc, char **args)
{
	t_data		data = {0};

	data.fractal = -1;
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
			if (get_input(&data, argc, args))
				data = init_mlx(data);
			else
				invalid_input(BAD_INPUT);
		}
		else
			invalid_input(BAD_INPUT);
	}
	return (0);
}
