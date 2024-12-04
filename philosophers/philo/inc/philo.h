/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:01:13 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/05 00:05:13 by dlopez-l         ###   ########.fr       */
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

typedef struct s_philo
{
	int		idx;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	struct s_table	*table;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}	t_fork;


typedef struct s_table
{
	t_philo			*philo;
	t_fork			*l_fork;
	t_fork			*r_fork;
	struct s_table	*right;
	struct s_table	*left;
}	t_table;

/*PHILO*/
void	*philo_start(void *i);

/*TABLE*/
t_table	*init_table(int n_philo);

/*FORKS*/
t_fork	*init_fork(void);
void	take_fork(t_fork *fork);
void	release_fork(t_fork *fork);

/*UTILS*/
int		ft_atoi(const char *nptr);

#endif