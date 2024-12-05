/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:17:01 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/05 12:56:37 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_loop(t_philo *philo)
{
	// while(actual_time - time_last_meal < time_to_die)
	while (1)
	{
		eat(philo);
	}
	
}

void	*philo_start(void *params)
{
	t_philo	*p;

	p = (t_philo *)params;
	philo_loop(p);
	return (NULL);
}
