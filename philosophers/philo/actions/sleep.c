/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:29:47 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/05/18 19:20:18 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_sleep(long long time, t_philo *p)
{
	long long	t;

	t = timestamp();
	while (1)
	{
		pthread_mutex_lock(p->data_m);
		if (p->is_dead)
		{
			pthread_mutex_unlock(p->data_m);
			break ;
		}
		pthread_mutex_unlock(p->data_m);
		if (calc_timestamp(t, timestamp()) >= time)
			break ;
		usleep(50);
	}
}
