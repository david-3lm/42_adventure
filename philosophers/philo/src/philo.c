/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:17:01 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/07 19:58:37 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_loop(t_philo *philo)
{
	while (!philo->is_dead)
	{
		if (!philo->is_dead)
			eat(philo);
	}
}

void	*philo_start(void *params)
{
	t_philo	*p;
	struct timeval tv;

	p = (t_philo *)params;
	gettimeofday(&tv, NULL);
	p->time_last_eat = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
	philo_loop(p);	
	return (NULL);
}
