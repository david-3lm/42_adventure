/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:03:21 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/06/06 11:22:01 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	finished_eat(t_table *table)
{
	t_table	*curr;
	int		i;

	i = 0;
	curr = table;
	if (!table->philo->is_dead)
		printf("Philosophers finished eating!\n");
	while (i < table->n_philo)
	{
		pthread_mutex_lock(curr->philo->data_m);
		curr->philo->is_dead = 1;
		pthread_mutex_unlock(curr->philo->data_m);
		curr = curr->right;
		i++;
	}
}

int	check_meals(t_table *table)
{
	t_table	*curr;
	int		count;
	int		i;

	i = 0;
	count = 0;
	curr = table;
	while (i < table->n_philo)
	{
		pthread_mutex_lock(curr->philo->data_m);
		if (curr->philo->meals >= table->min_meals)
			count++;
		pthread_mutex_unlock(curr->philo->data_m);
		i++;
		curr = curr->right;
	}
	if (count >= table->n_philo)
	{
		pthread_mutex_lock(curr->philo->console_m);
		finished_eat(table);
		pthread_mutex_unlock(curr->philo->console_m);
		return (1);
	}
	return (0);
}
