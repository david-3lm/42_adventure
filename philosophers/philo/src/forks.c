/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:17:37 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/05 00:07:19 by dlopez-l         ###   ########.fr       */
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