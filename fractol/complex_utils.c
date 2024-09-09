/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:22:11 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/09 16:37:43 by dlopez-l         ###   ########.fr       */
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