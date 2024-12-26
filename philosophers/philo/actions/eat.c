/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:29:41 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/26 12:28:03 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//HACER UNA FUNCION DE ESCRIBIR EN CONSOLA QUE TENGA AHI LOS MUTEX
void	eat(t_philo *p)
{
	if (!p->table->l_fork || !p->table->r_fork)
		return ;	
	if (p->idx % 2)
	{
		take_fork(p->table->l_fork);
		pthread_mutex_lock(&p->console_m);
		if (p->is_dead)
		{
			release_fork(p->table->l_fork);
			pthread_mutex_unlock(&p->console_m);
			return ;
		}
		printf("%lld %d has taken a fork.\n", calc_timestamp(p->table->start_time, timestamp()), p->idx);
		pthread_mutex_unlock(&p->console_m);
		take_fork(p->table->r_fork);
		pthread_mutex_lock(&p->console_m);
		if (p->is_dead)
		{
			release_fork(p->table->l_fork);
			release_fork(p->table->r_fork);
			pthread_mutex_unlock(&p->console_m);
			return ;
		}
		printf("%lld %d has taken a fork.\n", calc_timestamp(p->table->start_time, timestamp()), p->idx);
		pthread_mutex_unlock(&p->console_m);
	}
	else
	{
		take_fork(p->table->r_fork);
		pthread_mutex_lock(&p->console_m);
		if (p->is_dead)
		{
			release_fork(p->table->r_fork);
			pthread_mutex_unlock(&p->console_m);
			return ;
		}
		printf("%lld %d has taken a fork.\n", calc_timestamp(p->table->start_time, timestamp()), p->idx);
		pthread_mutex_unlock(&p->console_m);
		take_fork(p->table->l_fork);
		pthread_mutex_lock(&p->console_m);
		if (p->is_dead)
		{
			release_fork(p->table->r_fork);
			release_fork(p->table->l_fork);
			pthread_mutex_unlock(&p->console_m);
			return ;
		}
		printf("%lld %d has taken a fork.\n", calc_timestamp(p->table->start_time, timestamp()), p->idx);
		pthread_mutex_unlock(&p->console_m);
	}
	if (p->is_dead)
	{
		release_fork(p->table->l_fork);
		release_fork(p->table->r_fork);
		return ;
	}
	p->time_last_eat = timestamp();
	pthread_mutex_lock(&p->console_m);
	if (p->is_dead)
	{
		pthread_mutex_unlock(&p->console_m);
		return ;
	}
	printf("%lld %d is eating.\n", calc_timestamp(p->table->start_time, timestamp()), p->idx);
	pthread_mutex_unlock(&p->console_m);
	usleep(p->time_to_eat * 1000);
	pthread_mutex_lock(&p->console_m);
	if(p->is_dead)
	{
		release_fork(p->table->r_fork);
		release_fork(p->table->l_fork);
		pthread_mutex_unlock(&p->console_m);
		return ;
	}
	printf("%lld %d is sleeping.\n", calc_timestamp(p->table->start_time, timestamp()), p->idx);
	pthread_mutex_unlock(&p->console_m);
	release_fork(p->table->r_fork);
	release_fork(p->table->l_fork);
	ft_sleep(p->time_to_sleep, p);
}
