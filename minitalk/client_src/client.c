/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:18:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/17 11:58:56 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

t_global	g_client;

void	action(int signal)
{
	if (signal == SIGERR)
	{
		ft_printf("Errooor NOOOOOOOOOOOOOOOOOOO :&");
		exit(0);
	}
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
}

void	send_sig(void *data, size_t length, int pid)
{
	unsigned long long	value;
	int					i;

	value = 0;
	if (length == 8)
		value = *((unsigned char *)data);
	else if (length == 32)
		value = *((unsigned int *)data);
	i = length - 1;
	while (i >= 0)
	{
		if (value & (1ULL << i))
			kill(pid, BIT1);
		else
			kill(pid, BIT0);
		i--;
		while (!g_client.ready_to_continue)
			usleep(100);
		g_client.ready_to_continue = 0;
	}
	if (length == 32)
		g_client.size_sent = 1;
}

void	ft_kill(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		send_sig(&str[i], 8, pid);
		i++;
	}
	send_sig(&str[i], 8, pid);
	g_client.msg_sent = 1;
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
