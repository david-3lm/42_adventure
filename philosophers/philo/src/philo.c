/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:17:01 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/08 12:38:50 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_loop(t_philo *philo)
{
	if (philo->idx % 2)
		usleep(15000);
	while (!philo->is_dead)
	{
		eat(philo);
	}
}

void	*philo_start(void *params)
{
	t_philo	*p;

	p = (t_philo *)params;
	p->time_last_eat = timestamp();
	philo_loop(p);
	return (NULL);
}
