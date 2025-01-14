/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:01:13 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/14 15:46:29 by dlopez-l         ###   ########.fr       */
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
	int				meals;
	pthread_mutex_t	*console_m;
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
	int				min_meals;
	long long		start_time;
}	t_table;

/*PHILO*/
void		*philo_start(void *i);
void		philo_loop(t_philo *philo);
void		eat(t_philo *philo);
void		die(t_philo *philo);

/*TABLE*/
int			check_meals(t_table *table);
t_table		*init_table(int n_philo, int min_meals);

/*FORKS*/
t_fork		*init_fork(void);
void		take_fork(t_fork *fork);
void		release_fork(t_fork *fork);

/*DEATH*/
void		*check_death(void *table);
void		end_sim(t_table *table, long long tv);

/*UTILS*/
int			ft_atoi(const char *nptr);
int			check_input(int argc, char **argv);
void		ft_sleep(long long time, t_philo *p);
void		write_cmd(t_philo *p, const char *str);
void		clean_table(t_table *table);
long long	calc_timestamp(long long start, long long actual);
long long	timestamp(void);

#endif