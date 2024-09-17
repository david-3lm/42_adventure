/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:11:45 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/17 16:49:34 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	fact_complex(t_complex c)
{
	double	d;

	d = pow(c.real, 2) + pow(c.imaginary, 2);
	return (d);
}


t_complex	neg_pow(t_complex c, int p)
{
	double		num;
	t_complex	res;
	t_complex	pow_result;

	pow_result = complex_pow(c, p);
	num = fact_complex(pow_result);
	res.real = pow_result.real / num;
	res.imaginary = -pow_result.imaginary / num;
	return (res);
}

