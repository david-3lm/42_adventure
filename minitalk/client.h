/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:31:57 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/07 12:00:53 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "libimp/libft.h"
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

extern	t_global	g_client;
#endif