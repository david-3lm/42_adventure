/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:46:28 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/17 17:55:10 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	multibrot(t_complex z, t_complex c)
{
	int			i;

	i = 0;
	while (complex_abs(z) <= 4 && i < MAX_ITER)
	{
		z = complex_add(neg_pow(z, 2), c);
		i++;
	}
	return (i);
}
