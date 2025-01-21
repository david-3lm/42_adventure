/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:43:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/16 12:14:54 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_table	*handle_forks(t_table *table, t_table *curr, int i)
{
	if (i == 0)
	{
		if (table->n_philo > 1)
			curr->l_fork = init_fork();
		else
			curr->l_fork = NULL;
		curr->r_fork = init_fork();
	}
	else if (i == table->n_philo - 1)
	{
		curr->l_fork = curr->left->r_fork;
		curr->r_fork = table->l_fork;
	}
	else
	{
		curr->l_fork = curr->left->r_fork;
		curr->r_fork = init_fork();
	}
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
		curr->philo = malloc(sizeof(t_philo));
		if (!curr->philo)
			return (NULL);
		curr->philo->console_m = console;
		curr->n_philo = n_philo;
		curr->min_meals = min_meals;
		curr->start_time = table->start_time;
		curr = handle_forks(table, curr, i);
		if (!curr)
			return (NULL);
		i++;
	}
	return (table);
}
