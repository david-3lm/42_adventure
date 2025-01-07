/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:29:47 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/07 17:52:36 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_sleep(long long time, t_philo *p)
{
	long long	t;

	t = timestamp();
	while (!p->is_dead)
	{
		if (calc_timestamp(t, timestamp()) >= time)
			break ;
		usleep(50);
	}
}
