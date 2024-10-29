/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:31:23 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/10/29 18:41:49 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"

typedef struct s_msg
{
	int		size;
	char *content;
}	t_msg;


typedef struct s_server
{
	int		client_pid;
	int		server_pid;
	char	*msg;
}				t_server;

typedef struct s_global
{
	volatile sig_atomic_t	client_id;
	t_msg					msg;
}				t_global;

extern t_global	g_client;