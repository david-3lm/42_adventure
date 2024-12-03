/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:59:07 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/03 18:47:56 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

pthread_t	*init_threads(int n, pthread_attr_t attr, char **argv)
{
	int			i;
	t_params	*arg;
	pthread_t	*threads;

	i = 0;
	threads = malloc(n * sizeof(pthread_t));
	if (!threads)
		return (NULL);
	while (i < n)
	{
		arg = malloc(sizeof(t_params));
		if (!arg)
			return (NULL);
		arg->idx = i;
		arg->time_to_die = atoi(argv[2]);
		arg->time_to_eat = atoi(argv[3]);
		arg->time_to_sleep = atoi(argv[4]);
		pthread_create(&threads[i], &attr, philo_start, arg);
		i++;
	}
	return (threads);
}

int	main(int argc, char **argv)
{
	int				i;
	pthread_attr_t	attr;
	pthread_mutex_t	sum_mutex;
	pthread_t		*threads;

	i = 0;
	if (argc < 5 || argc > 7)
		return (1);
	pthread_mutex_init(&sum_mutex, NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	threads = init_threads(atoi(argv[1]), attr, argv);
	while (i < 0)
	{
		pthread_join(threads[i], NULL);
		i--;
	}
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&sum_mutex);
	pthread_exit (NULL);
	return (0);
}
