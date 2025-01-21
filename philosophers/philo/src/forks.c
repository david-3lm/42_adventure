/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:17:37 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/21 13:04:15 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
}

void	release_fork(t_fork *fork)
{
	pthread_mutex_unlock(&fork->mutex);
}

t_fork	*init_fork(void)
{
	t_fork	*fork;

	fork = malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	pthread_mutex_init(&fork->mutex, NULL);
	return (fork);
}

void	init_forks(t_table **curr, t_table *table, int i)
{
	if (i == 0)
	{
		if (table->n_philo > 1)
			(*curr)->l_fork = init_fork();
		else
			(*curr)->l_fork = NULL;
		(*curr)->r_fork = init_fork();
	}
	else if (i == table->n_philo - 1)
	{
		(*curr)->l_fork = (*curr)->left->r_fork;
		(*curr)->r_fork = table->l_fork;
	}
	else
	{
		(*curr)->l_fork = (*curr)->left->r_fork;
		(*curr)->r_fork = init_fork();
	}
}
