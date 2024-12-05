/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:17:01 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/05 23:56:40 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_loop(t_philo *philo)
{
	struct timeval	tv;
	long long		curr_time;
	// while(actual_time - time_last_meal < time_to_die)
	while (1)
	{
		gettimeofday(&tv, NULL);
		curr_time = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
		// printf("curr time => %lld | last eat => %lld\n", curr_time, philo->time_last_eat);
		if (curr_time - philo->time_last_eat > philo->time_to_die)
		{
			printf("ME MORIIIIII %d\n", philo->idx);
			break;
		}
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
