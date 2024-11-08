/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:03:51 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/08 17:50:27 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

void	handle_msg(int signal)
{
	static char	current_c = 0;
	static int	bit_idx = 0;

	if (signal == SIGUSR1)
		current_c |= (1 << (7 - bit_idx));
	bit_idx++;
	if (bit_idx == 8)
	{
		if (current_c < 0 || current_c >= 127)
		{
			ft_printf("Error al recibir el mensaje! :(\n");
			kill(g_server.client_id, SIGERR);
			save_msg(0);
			reset_all();
			bit_idx = 0;
			current_c = 0;
			return ;
		}
		save_msg(current_c);
		usleep(1000);
		if (current_c == '\0')
		{
			ft_printf("%s", g_server.msg.content);
			ft_printf("\n-----------------Enviando confirmacion a cliente: %d ---------------------\n", g_server.client_id);
			kill(g_server.client_id, SIGSUCC);
			reset_all();
		}
		else
			kill(g_server.client_id, SIGSUCC);
		bit_idx = 0;
		current_c = 0;
	}
	else
		kill(g_server.client_id, SIGSUCC);
}

void	handle_size(int signal)
{
	static int	current_n = 0;
	static int	bit_idx = 0;

	if (signal == BIT1)
		current_n |= (1 << (7 - bit_idx));
	bit_idx++;
	if (bit_idx == 8)
	{
		usleep(1000);
		g_server.msg.size = (int) current_n;
		ft_printf("Size of msg: %d\n", g_server.msg.size);
		bit_idx = 0;
		current_n = 0;
		g_server.size_recived = 1;
		g_server.msg.content = ft_calloc(g_server.msg.size + 1, 1);
		if (!g_server.msg.content)
		{
			ft_printf("Fallo malloc maniiiiiin");
			reset_all();
			return ; //PROGRAMAR GESTION DE ERRORES
		}
		kill(g_server.client_id, SIGSUCC);
	}
	else
		kill(g_server.client_id, SIGSUCC);
}
