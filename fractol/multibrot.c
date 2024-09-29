/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:46:28 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/29 20:15:11 by dlopez-l         ###   ########.fr       */
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
		z = complex_add(neg_pow(z, 2), c);
		i++;
	}
	return (i);
}
