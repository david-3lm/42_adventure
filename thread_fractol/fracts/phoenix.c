/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:50:40 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/26 15:50:24 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	phoenix(t_complex c, t_data data)
{
	t_complex	zn;
	t_complex	zn_1;
	t_complex	z_next;
	int			i;

	i = 0;
	zn = c;
	zn_1 = zn;
	while (i < data.iter)
	{
		z_next = complex_add(complex_add(complex_pow(zn, 2), data.c_juila), \
			complex_mult(data.p_pho, zn_1));
		zn_1 = zn;
		zn = z_next;
		if (complex_abs(zn) > 4)
			break ;
		i++;
	}
	return (i);
}
