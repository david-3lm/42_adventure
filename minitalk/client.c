/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:18:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/17 12:06:09 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"

void	action(int a)
{
	static int	received;

	received = 0;
	if (a == SIGUSR1)
	{
		printf("RECIBIDO SIGUSR1");
	}
	else
	{
		printf("%d\n", received);
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
		usleep(1000);
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
	ft_printf("Client PID: %d\n", getpid());
	if (argc != 3)
		return (0);

	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	ft_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
