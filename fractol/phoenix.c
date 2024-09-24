/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:50:40 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/24 21:24:24 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	calc_z0(t_data data, int x, int y)
{
	t_complex	z0;

	z0.real = data.min_c.real + (x / (double)WIDTH) * (data.max_c.real - data.min_c.real);
	z0.imaginary = data.min_c.imaginary + (y / (double)HEIGHT) * (data.max_c.imaginary - data.min_c.imaginary);
	return (z0);
}

int	phoenix(t_data data, int x, int y)
{
	t_complex	zn;
	t_complex	zn_1;
	t_complex	z_next;
	t_complex	c;
	t_complex	p;
	int			i;

	i = 0;
	zn = calc_z0(data, x, y);
	zn_1 = zn;
	c = (t_complex){0.269, 0.0};
	p = (t_complex){0.0, 0.01};
	while (i < MAX_ITER)
	{
		z_next = complex_add(complex_add(complex_mult(zn, zn), c), complex_mult(p, zn_1));
		zn_1 = zn;
		zn = z_next;
		if (complex_abs(zn) > 4)
			break ;
		i++;
	}
	return (i);
}


// int	phoenix(t_complex zn, t_complex z1)
// {
// 	t_complex	c;
// 	t_complex	p;
// 	t_complex	res;
// 	int			i;

// 	c = (t_complex){0.269, 0.0};
// 	p = (t_complex){0.0, 0.01};
// 	i = 0;
// 	while (complex_abs(res) <= 4 && i < MAX_ITER)
// 	{
// 		res = complex_add(complex_add(complex_pow(zn, 2), c), complex_mult(p, z1));
// 		phoenix(res, zn);
// 		i++;
// 	}
// 	return (i);
// }
