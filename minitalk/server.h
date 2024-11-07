/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:31:23 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/07 12:01:23 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "libimp/libft.h"
# include "global.h"

typedef struct s_msg
{
	int		size;
	char	*content;
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
	volatile int			size_recived;
	t_msg					msg;
}				t_global;

extern t_global	g_server;
#endif