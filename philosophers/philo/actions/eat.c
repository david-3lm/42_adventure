/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:29:41 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/05 12:56:12 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eat(t_philo *p)
{
	pthread_mutex_lock(&p->table->l_fork->mutex);
	printf("%d has taken a fork.\n", p->idx);
	pthread_mutex_lock(&p->table->r_fork->mutex);
	printf("%d has taken a fork.\n", p->idx);
	printf("%d is eating.\n", p->idx);
	// time_last_meal = actual_time;
	usleep(p->time_to_eat);
	pthread_mutex_unlock(&p->table->r_fork->mutex);
	pthread_mutex_unlock(&p->table->l_fork->mutex);
	printf("%d is sleeping.\n", p->idx);
	usleep(p->time_to_sleep);
}
