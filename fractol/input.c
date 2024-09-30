/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:29:47 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/30 10:43:35 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_input(t_data *data, int argc, char **args)
{
	if (data->fractal != 0)
	{
		if (argc < 4)
			return (0);
		data->c_juila.real = ft_atod(args[2]);
		data->c_juila.imaginary = ft_atod(args[3]);
		if (data->fractal == 2 && argc == 5)
			data->multi_pow = ft_atoi(args[4]);
		else
			data->multi_pow = 2;
		if (data->fractal == 3)
		{
			if (argc < 6)
				return (0);
			data->p_pho.real = ft_atod(args[4]);
			data->p_pho.imaginary = ft_atod(args[5]);
		}
	}
	return (1);
}
