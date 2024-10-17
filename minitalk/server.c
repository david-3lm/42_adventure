/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:18:08 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/17 11:58:12 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"

void	action(int signal, siginfo_t *info, void *context)
{
	static char	current_c = 0;
	static int	bit_idx = 0;
	static int	client_pid = 0;
	//static int	char_idx = 0;

	(void)context;
	(void)info;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signal == SIGUSR1)
		current_c |= (1 << (7 - bit_idx));
	bit_idx++;
	if (bit_idx == 8)
	{
		write(1, &current_c, 1);
		if (current_c == '\0')
		{
			write(1, "\n", 1);
			ft_printf("%d", client_pid);
			kill(client_pid, SIGUSR1);
		}
		bit_idx = 0;
		current_c = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: %d\n", getpid());
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
