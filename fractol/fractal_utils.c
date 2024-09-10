/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:15:28 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/10 16:01:45 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	calc_c(int x, int y, t_data data)
{
	t_complex	c;
	
	c.real = data.min_c.real + (double)x * (data.max_c.real - data.min_c.real) / WIDTH;
	c.imaginary = data.max_c.imaginary + (double)y * (data.min_c.imaginary - data.max_c.imaginary) / HEIGHT;
	return (c);
}
