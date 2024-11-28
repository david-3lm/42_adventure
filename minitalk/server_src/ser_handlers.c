/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:03:51 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/28 12:34:23 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

int	char_complete(char current_c)
{
	if (current_c < 0 || current_c >= 127)
	{
		ft_printf("Error al recibir el mensaje! :(\n");
		kill(g_server.client_id, SIGERR);
		save_msg(0);
		reset_all();
		current_c = 0;
		return (0);
	}
	save_msg(current_c);
	if (current_c == '\0')
	{
		ft_printf("%s\n", g_server.msg.content);
		kill(g_server.client_id, SIGSUCC);
		reset_all();
	}
	else
		kill(g_server.client_id, SIGSUCC);
	return (1);
}

void	handle_msg(int signal)
{
	static char	current_c = 0;
	static int	bit_idx = 0;

	if (signal == BIT1)
		current_c = (current_c * 2) + 1;
	else
		current_c *= 2;
	bit_idx++;
	if (bit_idx == 8)
	{
		char_complete(current_c);
		bit_idx = 0;
		current_c = 0;
	}
	else
		kill(g_server.client_id, SIGSUCC);
}

void	handle_size(int signal)
{
	static unsigned int	current_n = 0;
	static int			bit_idx = 0;

	if (signal == BIT1)
		current_n = (current_n * 2) + 1;
	else
		current_n *= 2;
	bit_idx++;
	if (bit_idx == 32)
	{
		g_server.msg.size = current_n;
		ft_printf("Size of msg: %d\n", g_server.msg.size);
		g_server.msg.content = ft_calloc(g_server.msg.size + 1, 1);
		if (!g_server.msg.content)
		{
			reset_all();
			return ;
		}
		bit_idx = 0;
		current_n = 0;
		g_server.size_recived = 1;
		kill(g_server.client_id, SIGSUCC);
	}
	else
		kill(g_server.client_id, SIGSUCC);
}
