/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:29:41 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/05 17:49:53 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eat(t_philo *p)
{
	if (p->idx % 2)
	{
		take_fork(p->table->l_fork);
		printf("%d has taken a fork.\n", p->idx);
		take_fork(p->table->r_fork);
		printf("%d has taken a fork.\n", p->idx);
	}
	else
	{
		take_fork(p->table->r_fork);
		printf("%d has taken a fork.\n", p->idx);
		take_fork(p->table->l_fork);
		printf("%d has taken a fork.\n", p->idx);
	}
	printf("%d is eating.\n", p->idx);
	// time_last_meal = actual_time;
	usleep(p->time_to_eat);
	printf("%d is sleeping.\n", p->idx);
	pthread_mutex_unlock(&p->table->r_fork->mutex);
	pthread_mutex_unlock(&p->table->l_fork->mutex);
	usleep(p->time_to_sleep);
}
