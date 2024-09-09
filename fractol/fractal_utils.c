/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:15:28 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/09 17:14:18 by dlopez-l         ###   ########.fr       */
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