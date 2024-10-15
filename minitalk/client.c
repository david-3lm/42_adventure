/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:18:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/15 19:56:51 by dlopez-l         ###   ########.fr       */
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

void	ft_kill(int pid, char *str)
{
	(void)str;
	kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 3)
		return (0);
	signal(SIGUSR1, action);
	ft_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
