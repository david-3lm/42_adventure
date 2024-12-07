/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:04:14 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/07 19:58:29 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	end_sim(t_table *table)
{
	t_table	*curr;
	int		i;

	i = 0;
	curr = table;
	printf("%d died.\n", curr->philo->idx);
	while (i < table->n_philo)
	{
		curr->philo->is_dead = 1;
		curr = curr->right;
		i++;
	}
}

void	*check_death(void *table)
{
	t_table			*curr;
	struct timeval	tv;
	long long		curr_time;

	curr = (t_table *)table;
	while (1)
	{
		gettimeofday(&tv, NULL);
		curr_time = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
		if (curr_time - curr->philo->time_last_eat > curr->philo->time_to_die)
		{
			pthread_mutex_lock(&curr->philo->console_m);
			end_sim(curr);
			pthread_mutex_unlock(&curr->philo->console_m);
			break;
		}
		curr = curr->right;
	}
	return (NULL);
}
