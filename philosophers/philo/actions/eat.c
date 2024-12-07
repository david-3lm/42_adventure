/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:29:41 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/07 19:57:38 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

//HACER UNA FUNCION DE ESCRIBIR EN CONSOLA QUE TENGA AHI LOS MUTEX
void	eat(t_philo *p)
{
	struct timeval tv;
	
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
		printf("%d has taken a fork.\n", p->idx);
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
		printf("%d has taken a fork.\n", p->idx);
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
		printf("%d has taken a fork.\n", p->idx);
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
		printf("%d has taken a fork.\n", p->idx);
		pthread_mutex_unlock(&p->console_m);
	}
	if (p->is_dead)
	{
		release_fork(p->table->l_fork);
		release_fork(p->table->r_fork);
		return ;
	}
	gettimeofday(&tv, NULL);
	p->time_last_eat = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
	pthread_mutex_lock(&p->console_m);
	if (p->is_dead)
	{
		pthread_mutex_unlock(&p->console_m);
		return ;
	}
	printf("%d is eating.\n", p->idx);
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
	printf("%d is sleeping.\n", p->idx);
	pthread_mutex_unlock(&p->console_m);
	release_fork(p->table->r_fork);
	release_fork(p->table->l_fork);
	usleep(p->time_to_sleep * 1000);
}
