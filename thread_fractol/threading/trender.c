/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trender.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:01:35 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/26 16:34:09 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	draw_pixel(t_data *img, int x, int y)
{
	int	res;
	int	color;
	t_complex c;

	c = calc_c(x, y, *img);
	if (img->fractal == 0)
		res = mandelbrot(c, *img);
	else if (img->fractal == 1)
		res = julia(c, *img);
	else if (img->fractal == 2)
		res = multibrot(c, *img);
	else
		res = phoenix(c, *img);
	color = 0x00000000;
	if (res != img->iter)
		color = get_color(res, img->color_palette, *img);
	my_mlx_pixel_put(img, x, y, color);
}

void *thread_draw(void *arg) 
{
    t_thread_data *t_data = (t_thread_data *)arg;
    int x, y;

    for (y = t_data->start_row; y < t_data->end_row; y++) 
	{
        for (x = 0; x < WIDTH; x++) 
		{
            draw_pixel(t_data->data, x, y);
        }
    }
    return NULL;
}
