/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:46:28 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/30 11:07:10 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	multibrot(t_complex z, t_data data)
{
	int			i;
	t_complex	c;

	i = 0;
	c = data.c_juila;
	while (complex_abs(z) <= 4 && i < data.iter)
	{
		if (data.multi_pow < 0)
			z = complex_add(neg_pow(z, -data.multi_pow), c);
		else if (data.multi_pow > 0)
			z = complex_add(complex_pow(z, data.multi_pow), c);
		i++;
	}
	return (i);
}
