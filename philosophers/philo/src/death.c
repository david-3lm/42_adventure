/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:04:14 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/05/18 19:13:24 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	end_sim(t_table *table, long long tv)
{
	t_table	*curr;
	int		i;

	i = 0;
	curr = table;
	printf("%lld %d died\n", \
	calc_timestamp(table->start_time, tv), curr->philo->idx);
	while (i < table->n_philo)
	{
		pthread_mutex_lock(curr->philo->data_m);
		curr->philo->is_dead = 1;
		pthread_mutex_unlock(curr->philo->data_m);
		curr = curr->right;
		i++;
	}
}

void	*check_death(void *table)
{
	t_table			*curr;

	curr = (t_table *)table;
	while (1)
	{
		if (curr->min_meals != -1)
		{
			if (check_meals((t_table *)table))
				break ;
		}
		pthread_mutex_lock(curr->philo->data_m);
		if (calc_timestamp(curr->philo->time_last_eat, timestamp()) \
		> curr->philo->time_to_die)
		{
			pthread_mutex_unlock(curr->philo->data_m);
			pthread_mutex_lock(curr->philo->console_m);
			end_sim(curr, timestamp());
			pthread_mutex_unlock(curr->philo->console_m);
			break ;
		}
		pthread_mutex_unlock(curr->philo->data_m);
		curr = curr->right;
	}
	return (NULL);
}
