/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inerror.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:00:10 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/26 15:48:56 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	invalid_input(char *msg)
{
	ft_printf("%s", msg);
}

void	clear_mem(void **p)
{
	free(*p);
	*p = NULL;
}

int	close_win(t_data *vars)
{
	if (vars)
	{
		mlx_loop_end(vars->mlx);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		clear_mem((void **)&vars->mlx);
	}
	exit (0);
	return (0);
}
