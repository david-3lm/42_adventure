/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:03:21 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/07 16:18:05 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	finished_eat(t_table *table)
{
	t_table	*curr;
	int		i;

	i = 0;
	curr = table;
	pthread_mutex_lock(&table->philo->console_m);
	if (!table->philo->is_dead)
		printf("Philosophers finished eating!\n");
	while (i < table->n_philo)
	{
		curr->philo->is_dead = 1;
		curr = curr->right;
		i++;
	}
	pthread_mutex_unlock(&table->philo->console_m);
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
		if (curr->philo->meals >= table->min_meals)
			count++;
		i++;
		curr = curr->right;
	}
	if (count >= table->n_philo)
	{
		finished_eat(table);
		return (1);
	}
	return (0);
}
