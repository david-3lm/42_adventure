/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:59:15 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/26 15:50:13 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	julia(t_complex z, t_data data)
{
	int			i;
	t_complex	c;

	i = 0;
	c = data.c_juila;
	while (complex_abs(z) <= 4 && i < data.iter)
	{
		z = complex_add((complex_pow(z, 2)), c);
		i++;
	}
	return (i);
}
