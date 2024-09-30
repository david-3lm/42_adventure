/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:11:45 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/30 11:01:38 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	fact_complex(t_complex c)
{
	double		d;
	t_complex	res;

	d = pow(c.real, 2) + pow(c.imaginary, 2);
	if (d == 0)
	{
		res = (t_complex){0, 0};
		return (res);
	}
	res.real = c.real / d;
	res.imaginary = -c.imaginary / d;
	return (res);
}

t_complex	neg_pow(t_complex c, int p)
{
	t_complex	res;
	t_complex	pow_result;

	pow_result = complex_pow(c, p);
	res = fact_complex(pow_result);
	return (res);
}
