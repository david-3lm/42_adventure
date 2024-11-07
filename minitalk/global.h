/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:01:28 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/11/07 12:03:48 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include <signal.h>
# define WRONG_CHAR SIGUSR2
# define ERROR SIGUSR2
# define CONNECTED SIGUSR1
# define CHAR_SENT SIGUSR1
#endif