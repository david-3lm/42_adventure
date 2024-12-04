/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:17:01 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/05 00:05:54 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	philo_loop(t_philo *philo)
{
	(void)philo;
}

void	*philo_start(void *params)
{
	t_philo	*p = (t_philo *)params;

	printf("Philosopher %d:\n", p->idx);
	printf("Time to die: %d\n", p->time_to_die);
	printf("Left fork mutex: %p\n", (void *)&p->table->l_fork->mutex);
	printf("Right fork mutex: %p\n", (void *)&p->table->r_fork->mutex);

	// Simulación (ejemplo: intentar tomar los tenedores)
	pthread_mutex_lock(&p->table->l_fork->mutex);
	printf("Philosopher %d took the left fork.\n", p->idx);
	pthread_mutex_lock(&p->table->r_fork->mutex);
	printf("Philosopher %d took the right fork.\n", p->idx);

	// Comer
	pthread_mutex_unlock(&p->table->r_fork->mutex);
	pthread_mutex_unlock(&p->table->l_fork->mutex);
	printf("Philosopher %d finished eating.\n", p->idx);

	return (NULL);
}
