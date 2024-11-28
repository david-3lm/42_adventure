/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:31:57 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/28 12:19:30 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "../libimp/libft.h"
# include "global.h"

typedef struct s_client
{
	pid_t	client_pid;
	pid_t	server_pid;
	char	*msg;
}	t_client;

typedef struct s_global
{
	int						pid;
	volatile sig_atomic_t	ready_to_continue;
	volatile sig_atomic_t	size_sent;
	volatile sig_atomic_t	msg_sent;
	volatile sig_atomic_t	connection;
}	t_global;

void	handle_connection(int signal);
void	handle_size(int signal);
void	handle_msg(int signal);
void	handle_signals(int pid, char **argv);
void	ft_kill(int pid, char *str);
void	send_char(int pid, int c);
void	send_int(int pid, int value);
void	send_sig(void *data, size_t length, int pid);
void	action(int signal);

extern t_global	g_client;
#endif