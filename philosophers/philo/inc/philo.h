/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:01:13 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/07 19:09:03 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/timeb.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				idx;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long long		time_last_eat;
	struct s_table	*table;
	int				is_dead;
	pthread_mutex_t	console_m;
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
	int				n_philo;
}	t_table;

/*PHILO*/
void	*philo_start(void *i);
void	philo_loop(t_philo *philo);
void	eat(t_philo *philo);
void	die(t_philo *philo);

/*TABLE*/
t_table	*init_table(int n_philo);

/*FORKS*/
t_fork	*init_fork(void);
void	take_fork(t_fork *fork);
void	release_fork(t_fork *fork);

/*DEATH*/
void	*check_death(void *table);
void	end_sim(t_table *table);


/*UTILS*/
int		ft_atoi(const char *nptr);

#endif