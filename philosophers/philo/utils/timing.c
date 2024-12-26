/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:58:26 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/21 13:18:12 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	calc_timestamp(struct timeval start, struct timeval actual)
{
	long	ms_start;
	long	ms_act;

	ms_start = (start.tv_sec * 1000LL) + (start.tv_usec / 1000);
	ms_act = (actual.tv_sec * 1000LL) + (actual.tv_usec / 1000);
	return (ms_act - ms_start);
}
