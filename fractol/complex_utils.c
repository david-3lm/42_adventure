/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:22:11 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/10 19:23:31 by dlopez-l         ###   ########.fr       */
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
	if (b > 2)
	{
		return (complex_mult(complex_pow(a, b - 1), a));
	}
	else if (b == 2)
	{
		return (complex_mult(a, a));
	}
	return (a);
}

t_complex exp_complex(t_complex z) {
    t_complex result;
    double exp_real = exp(z.real); // exp(x)

    result.real = exp_real * cos(z.imaginary); // exp(x) * cos(y)
    result.imaginary = exp_real * sin(z.imaginary); // exp(x) * sin(y)

    return result;
}
