/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:30:30 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/26 15:49:08 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	create_limits(t_data *data)
{
	data->max_c.real = 4.0;
	data->min_c.real = -4.0;
	data->min_c.imaginary = -4.0;
	data->max_c.imaginary = data->min_c.imaginary + \
		(data->max_c.real - data->min_c.real) * HEIGHT / WIDTH;
}

t_data	init_mlx(t_data data)
{
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractalin");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.bits_per_pixel = 0;
	data.line_length = 0;
	data.endian = 0;
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
		&data.line_length, &data.endian);
	data.color_palette = 1;
	data.iter = MAX_ITER;
	create_limits(&data);
	print_fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, hook_mouse, &data);
	mlx_hook(data.win, 17, 1L << 0, close_win, &data);
	mlx_loop(data.mlx);
	return (data);
}
