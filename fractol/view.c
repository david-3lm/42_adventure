/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:03:49 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/08/29 21:12:54 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int	move(int keycode, t_data *data)
{
	if (keycode == K_UP)
		data->off_y -= 0.1;
	if (keycode == K_DOWN)
		data->off_y += 0.1;
	if (keycode == K_RIGHT)
		data->off_y += 0.1;
	if (keycode == K_LEFT)
		data->off_y -= 0.1;
	print_fractal(data->img);
	return (0);
}