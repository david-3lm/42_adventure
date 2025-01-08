/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:29:41 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/08 11:35:20 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	eat(t_philo *p)
{
	if (!p->table->l_fork || !p->table->r_fork)
		return ;
	take_fork(p->table->l_fork);
	write_cmd(p, "has taken a fork");
	take_fork(p->table->r_fork);
	write_cmd(p, "has taken a fork");
	p->time_last_eat = timestamp();
	write_cmd(p, "is eating");
	ft_sleep(p->time_to_eat, p);
	p->meals++;
	release_fork(p->table->r_fork);
	release_fork(p->table->l_fork);
	write_cmd(p, "is sleeping");
	ft_sleep(p->time_to_sleep, p);
	write_cmd(p, "is thinking");
}
