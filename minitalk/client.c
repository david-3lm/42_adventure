/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:18:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/29 18:51:52 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_global	g_server;

void	action(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("El servidor ha recibido el mensaje correctamente :D\n");
		_exit(0);	
	}
	else if (signal == SIGUSR2)
	{
		g_server.ready_to_continue = 1;
	}
}

void	send_char(int pid, char c)
{
	int	i;
	int	err;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << (7 - i)))
			err = kill(pid, SIGUSR1);
		else
			err = kill(pid, SIGUSR2);
		while (!g_server.ready_to_continue)
			usleep(3000);
		g_server.ready_to_continue = 0;
		i++;
		if (err)
			ft_printf("Erroooor\n");
	}
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
	ft_kill(ft_atoi(argv[1]), argv[2]);
	return (0);
}
