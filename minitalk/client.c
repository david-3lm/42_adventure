/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:18:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/17 13:13:30 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"

void	action(int signal)
{
	printf("Action recibida");
	if (signal == SIGUSR1)
	{
		printf("RECIBIDO SIGUSR1");
	}
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << (7 - i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
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
	ft_kill(ft_atoi(argv[1]), argv[2]);
	pause();
	return (0);
}
