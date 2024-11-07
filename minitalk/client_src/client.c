/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:18:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/07 17:29:06 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

t_global	g_client;

void	action(int signal)
{
	if (!g_client.connection)
	{
		handle_connection(signal);
		return ;
	}
	if (!g_client.size_sent)
	{
		handle_size(signal);
		return ;
	}
	if (!g_client.msg_sent)
	{
		handle_msg(signal);
		return ;
	}
	if (signal == SIGERR)
	{
		ft_printf("Errooor NOOOOOOOOOOOOOOOOOOO :&");
		exit(0);
	}
}

void	send_char(int pid, int c)
{
	int	i;
	int	err;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << (7 - i)))
			err = kill(pid, BIT1);
		else
			err = kill(pid, BIT0);
		while (!g_client.ready_to_continue)
			usleep(3000);
		g_client.ready_to_continue = 0;
		i++;
		if (err)
			ft_printf("Erroooor\n");
	}
	if (!g_client.size_sent)
		g_client.size_sent = 1;
	i = 0;
}

void	ft_kill(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, 0);
	g_client.msg_sent = 1;
}

void	handle_signals(int pid, char **argv)
{
	int	tries;

	tries = 0;
	while (!g_client.connection && tries < 10)
	{
		kill(pid, SIGUSR1);
		usleep(2000);
		tries++;
	}
	// SI SE PASA DE TIEMPO EXIT
	if (tries >= 10)
	{
		ft_printf("Mensaje no enviado :(\n");
		g_client.msg_sent = 1;
		return ;
	}
	if (!g_client.size_sent)
		send_char(pid, ft_strlen(argv[2]));
	else
		ft_kill(pid, argv[2]);

}

int	main(int argc, char **argv)
{
	struct sigaction	s_sigaction;

	ft_printf("Client PID: %d\n", getpid());
	if (argc != 3)
		return (0);
	s_sigaction.sa_handler = action;
	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_flags = 0;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	g_client.size_sent = 0;
	g_client.msg_sent = 0;
	while (!g_client.msg_sent)
	{
		handle_signals(ft_atoi(argv[1]), argv);
	}
	ft_printf("MENSAJE ENVVIADO :D\n");
	return (0);
}
