/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:45:27 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/17 17:21:15 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c)
{
	int			i;
	t_complex	z;

	z.imaginary = 0;
	z.real = 0;
	i = 0;
	while (complex_abs(z) <= 4 && i < MAX_ITER)
	{
		z = complex_add(complex_pow(z, 2), c);
		i++;
	}
	return (i);
}
