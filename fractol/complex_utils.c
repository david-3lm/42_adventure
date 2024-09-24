/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:22:11 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/24 19:29:28 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	res;

	res.real = a.real + b.real;
	res.imaginary = a.imaginary + b.imaginary;
	return (res);
}

t_complex	complex_mult(t_complex a, t_complex b)
{
	t_complex	res;

	res.real = (a.real * b.real) - (a.imaginary * b.imaginary);
	res.imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
	return (res);
}

double	complex_abs(t_complex complex)
{
	double	r;

	r = pow(complex.real, 2) + pow(complex.imaginary, 2);
	return (r);
}

t_complex	complex_pow(t_complex a, int b)
{
	t_complex	result;
	t_complex	base;
	int			exponent;

	result.real = 1;
	result.imaginary = 0;
	base = a;
	exponent = b;
	if (exponent < 0)
	{
		base = (t_complex){1.0 / base.real, -1.0 / base.imaginary};
		exponent = -exponent;
	}

	while (exponent > 0)
	{
		if (exponent % 2 == 1)
		{
			result = complex_mult(result, base);
		}
		base = complex_mult(base, base);
		exponent /= 2;
	}
	return (result);
}
