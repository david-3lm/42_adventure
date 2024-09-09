/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:03:49 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/08/30 01:32:59 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int	move(int keycode, t_data *data)
{
	if (keycode == K_UP)
		data->off_y -= 0.01;
	if (keycode == K_DOWN)
		data->off_y += 0.01;
	if (keycode == K_RIGHT)
		data->off_x += 0.01;
	if (keycode == K_LEFT)
		data->off_x -= 0.01;
	mlx_clear_window(data->mlx, data->win);
	print_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}