/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:30:32 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/14 15:47:39 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	write_cmd(t_philo *p, const char *str)
{
	pthread_mutex_lock(p->console_m);
	if (!p->is_dead)
		printf("%lld %d %s\n", \
		calc_timestamp(p->table->start_time, timestamp()), p->idx, str);
	pthread_mutex_unlock(p->console_m);
}
