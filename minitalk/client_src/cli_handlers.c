/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:18:21 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/07 15:12:29 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

void	handle_connection(int signal)
{
	if (signal == SERV_FREE)
	{
		g_client.connection = 1;
		ft_printf("Connected!\n");
	}
	else if (signal == SERV_OCC)
		ft_printf("Server busy...\n");
	return ;
}

void	handle_size(int signal)
{
	(void) signal;
	g_client.ready_to_continue = 1;
	return ;
}

void	handle_msg(int signal)
{
	if (signal == SIGSUCC)
	{
		if (g_client.msg_sent)
		{
			ft_printf("El servidor ha recibido el mensaje correctamente :D\n");
			_exit(0);	
		}
		g_client.ready_to_continue = 1;
	}
	if (signal == SIGERR)
	{
		ft_printf("Error al enviar mensaje :(\n");
		exit(0);
	}
}
