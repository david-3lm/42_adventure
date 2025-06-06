/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:17:01 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/06/06 11:18:01 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_loop(t_philo *philo)
{
	if (philo->idx % 2)
		usleep(15000);
	pthread_mutex_lock(philo->data_m);
	while (!philo->is_dead)
	{
		pthread_mutex_unlock(philo->data_m);
		eat(philo);
		if (philo->idx % 2)
			usleep(1000);
		pthread_mutex_lock(philo->data_m);
	}
	pthread_mutex_unlock(philo->data_m);
}

void	*philo_start(void *params)
{
	t_philo	*p;

	p = (t_philo *)params;
	pthread_mutex_lock(p->data_m);
	p->time_last_eat = timestamp();
	pthread_mutex_unlock(p->data_m);
	philo_loop(p);
	return (NULL);
}
