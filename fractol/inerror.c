/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inerror.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:00:10 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/27 14:14:12 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	invalid_input(char *msg)
{
	ft_printf("%s", msg);
}

int	close_win(int keycode, t_data *vars)
{
	(void)keycode;
	exit(0);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
