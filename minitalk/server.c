/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:18:08 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/29 20:10:08 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_global	g_client;

void	handle_msg(int signal)
{
	static char	current_c = 0;
	static int	bit_idx = 0;

	if (signal == SIGUSR1)
		current_c |= (1 << (7 - bit_idx));
	bit_idx++;
	if (bit_idx == 8)
	{
		write(1, &current_c, 1);
		usleep(1000);
		if (current_c == '\0')
		{
			ft_printf("\nEnviando confirmacion a cliente: %d\n", g_client.client_id);
			kill(g_client.client_id, SIGUSR1);
			g_client.client_id = 0;
		}
		else
			kill(g_client.client_id, SIGUSR2);
		bit_idx = 0;
		current_c = 0;
	}
	else
		kill(g_client.client_id, SIGUSR2);
}

void	action(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (!g_client.client_id)
		g_client.client_id = info->si_pid;
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
	while (1)
		sleep(2);
	return (0);
}
