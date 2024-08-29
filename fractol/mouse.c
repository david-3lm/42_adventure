/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:11:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/08/29 19:28:46 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_mouse(int keycode, int x, int y, t_data *mlx)
{
	if (keycode == 5)
	{
		x = y;
		y = x;
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	return (0);
}

