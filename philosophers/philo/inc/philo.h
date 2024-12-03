/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:01:13 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/03 16:36:20 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/timeb.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_params
{
	int	idx;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_params;

void	*philo_start(void *i);
#endif