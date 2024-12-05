/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:17:01 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/05 17:42:07 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_loop(t_philo *philo)
{


	// while(actual_time - time_last_meal < time_to_die)
	while (1)
	{
		printf("Philosopher %d:\n", philo->idx);
		printf("Left fork mutex: %p, philo N = %d\n", (void *)&philo->table->l_fork->mutex, philo->idx);
		printf("Right fork mutex: %p, philo N = %d\n", (void *)&philo->table->r_fork->mutex, philo->idx);
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
