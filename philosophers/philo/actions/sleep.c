/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:29:47 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/26 12:28:37 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_sleep(long long time, t_philo *p)
{
	long long	t;

	t = timestamp();
	while (!p->is_dead)
	{
		if (calc_timestamp(t, timestamp()) >= time)
			break ;
		usleep(50);
	}
}