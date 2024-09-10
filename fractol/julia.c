/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:59:15 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/10 20:00:26 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex z)
{
	int			i;
	t_complex	c;

	c.real = 0.285;
	c.imaginary = -0.01;
	i = 0;
	while (complex_abs(z) <= 4 && i < MAX_ITER)
	{
		z = complex_add((complex_pow(z, 2)), c);
		i++;
	}
	return (i);
}
