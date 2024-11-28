/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:18:21 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/28 12:26:26 by dlopez-l         ###   ########.fr       */
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

void	handle_signals(int pid, char **argv)
{
	unsigned int	size;
	int				tries;

	tries = 0;
	while (!g_client.connection && tries < 10)
	{
		kill(pid, SIGUSR1);
		usleep(2000);
		tries++;
	}
	if (tries >= 10)
	{
		ft_printf("Mensaje no enviado :(\n");
		g_client.msg_sent = 1;
		return ;
	}
	if (!g_client.size_sent)
	{
		size = ft_strlen(argv[2]);
		send_sig(&(size), 32, pid);
	}
	else
		ft_kill(pid, argv[2]);
}
