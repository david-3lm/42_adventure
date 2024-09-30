/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inerror.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:00:10 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/09/30 11:29:54 by dlopez-l         ###   ########.fr       */
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
	(void)vars;
	exit(1);
	return (0);
}
