/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:18:08 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/16 13:06:03 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

t_global	g_server;

void	reset_all(void)
{
	ft_bzero(g_server.msg.content, g_server.msg.size);
	g_server.msg.size = 0;
	free(g_server.msg.content);
	g_server.msg.content = NULL;
	g_server.size_recived = 0;
	g_server.client_id = 0;
	ft_printf("Reseteado\n");
}

void	save_msg(char c)
{
	static int	i = 0;

	if (i < g_server.msg.size)
	{
		g_server.msg.content[i] = c;
		i++;
	}
	if (c == '\0')
		i = 0;
}

void	action(int signal, siginfo_t *info, void *ctx)
{
	(void)ctx;
	if (!g_server.client_id)
	{
		g_server.client_id = info->si_pid;
		kill(info->si_pid, SERV_FREE);
		return ;
	}
	else if (g_server.client_id != info->si_pid)
	{
		kill(info->si_pid, SERV_OCC);
		kill(g_server.client_id, SIGSUCC);
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
		usleep(2000);
	return (0);
}
