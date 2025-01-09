/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:34:30 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/09 12:29:50 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_input(t_philo *philo)
{
	if (philo->time_last_eat < 0)
		return (0);
	if (philo->time_to_eat < 0)
		return (0);
	if (philo->time_to_die < 0)
		return (0);
	if (philo->time_to_sleep < 0)
		return (0);
	return (1);
}

void	clean_table(t_table *table)
{
	t_table	*curr;
	int		i;

	i = 0;
	curr = table->right;
	while (i < table->n_philo)
	{
		free(curr->philo);
		pthread_mutex_destroy(&curr->l_fork->mutex);
		curr = curr->right;
		i++;
	}
}
