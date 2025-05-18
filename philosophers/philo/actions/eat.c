/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:29:41 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/05/18 19:22:12 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_forks(t_philo *p)
{
	if (p->idx % 2 == 0)
	{
		take_fork(p->table->l_fork);
		write_cmd(p, "has taken a fork");
		take_fork(p->table->r_fork);
		write_cmd(p, "has taken a fork");
	}
	else
	{
		take_fork(p->table->r_fork);
		write_cmd(p, "has taken a fork");
		take_fork(p->table->l_fork);
		write_cmd(p, "has taken a fork");
	}
}

void	eat(t_philo *p)
{
	if (!p->table->l_fork || !p->table->r_fork)
		return ;
	take_forks(p);
	pthread_mutex_lock(p->data_m);
	p->time_last_eat = timestamp();
	pthread_mutex_unlock(p->data_m);
	write_cmd(p, "is eating");
	ft_sleep(p->time_to_eat, p);
	p->meals++;
	release_fork(p->table->r_fork);
	release_fork(p->table->l_fork);
	write_cmd(p, "is sleeping");
	ft_sleep(p->time_to_sleep, p);
	write_cmd(p, "is thinking");
}
