/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:43:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/21 13:04:03 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_table	*handle_forks(t_table *table, t_table *curr, int i)
{
	init_forks(&curr, table, i);
	if ((!curr->l_fork && table->n_philo > 1) || !curr->r_fork)
		return (NULL);
	if (i == table->n_philo - 1)
	{
		curr->right = table;
		table->left = curr;
	}
	else
	{
		if (table->n_philo == 1)
			curr->right = curr;
		curr->right = malloc(sizeof(t_table));
		if (!curr->right)
			return (NULL);
		curr->right->left = curr;
		curr = curr->right;
	}
	return (curr);
}

t_table	*handle_table(pthread_mutex_t *c, int m, t_table *curr, t_table *table)
{
	curr->philo = malloc(sizeof(t_philo));
	if (!curr->philo)
		return (NULL);
	curr->philo->console_m = c;
	curr->n_philo = table->n_philo;
	curr->min_meals = m;
	curr->start_time = table->start_time;
	return (curr);
}

t_table	*init_table(int n_philo, int min_meals)
{
	t_table			*table;
	t_table			*curr;
	pthread_mutex_t	*console;
	int				i;

	i = 0;
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->start_time = timestamp();
	console = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(console, NULL);
	curr = table;
	table->n_philo = n_philo;
	while (i < n_philo)
	{
		curr = handle_table(console, min_meals, curr, table);
		curr = handle_forks(table, curr, i);
		if (!curr)
			return (NULL);
		i++;
	}
	return (table);
}
