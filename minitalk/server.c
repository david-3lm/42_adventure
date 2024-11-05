/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:18:08 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/05 14:24:42 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_global	g_server;

void	reset_all()
{
	ft_bzero(g_server.msg.content, g_server.msg.size);
	g_server.msg.size = 0;
	free(g_server.msg.content);
	g_server.msg.content = NULL;
	g_server.size_recived = 0;
	g_server.client_id = 0;
}

void	handle_size(int signal)
{
	static int	current_n = 0;
	static int	bit_idx = 0;

	if (signal == SIGUSR1)
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
		g_server.msg.content = ft_calloc(g_server.msg.size, 1);
		if (!g_server.msg.content)
		{
			ft_printf("Fallo malloc maniiiiiin");
			return ; //PROGRAMAR GESTION DE ERRORES
		}
		kill(g_server.client_id, SIGUSR1);
	}
	else
		kill(g_server.client_id, SIGUSR2);
}

void save_msg(char c)
{
	static int	i = 0;

	g_server.msg.content[i] = c;
	i++;
	if (c == '\0')
		i = 0;
}

void	handle_msg(int signal)
{
	static char	current_c = 0;
	static int	bit_idx = 0;

	if (signal == SIGUSR1)
		current_c |= (1 << (7 - bit_idx));
	bit_idx++;
	if (bit_idx == 8)
	{
		save_msg(current_c);
		usleep(1000);
		if (current_c == '\0')
		{
			ft_printf("%s", g_server.msg.content);
			ft_printf("\nEnviando confirmacion a cliente: %d\n", g_server.client_id);
			kill(g_server.client_id, SIGUSR1);
			reset_all();
		}
		else
			kill(g_server.client_id, SIGUSR2);
		bit_idx = 0;
		current_c = 0;
	}
	else
		kill(g_server.client_id, SIGUSR2);
}

void	action(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (!g_server.client_id)
	{
		g_server.client_id = info->si_pid;	
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	else if (g_server.client_id != info->si_pid)
	{
		kill(info->si_pid, SIGUSR1);
		return ;	
	}
	if (!g_server.size_recived)
		handle_size(signal);
	else
		handle_msg(signal);
}

int	main(void)
{
	struct sigaction	s_sigaction;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigaction.sa_mask);
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	g_server.size_recived = 0;
	while (1)
		sleep(2);
	return (0);
}
