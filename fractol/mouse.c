/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:11:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/09 12:39:56 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_mouse(int keycode, int x, int y, t_data *data)
{
	x = y;
	y = x;
	if (keycode == 1)
	{
		//ZOOM IN
		data->zoom += 0.1;
	}
	if (keycode == 5)
	{
		//ZOOM OUT
		data->zoom -= 0.1;
	}
	mlx_clear_window(data->mlx, data->win);
	print_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

