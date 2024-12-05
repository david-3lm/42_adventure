/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:59:07 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/05 12:41:14 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

pthread_t	*init_threads(int n, pthread_attr_t attr, char **argv)
{
	int				i;
	t_philo			*philo;
	t_table			*table;
	t_table			*curr;
	pthread_t		*threads;

	i = 0;
	table = init_table(n);
	threads = malloc(n * sizeof(pthread_t));
	if (!threads || !table)
		return (NULL);
	curr = table;
	while (i < n)
	{
		philo = curr->philo;
		philo->idx = i;
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
		philo->table = curr;
		pthread_create(&threads[i], &attr, philo_start, philo);
		curr = curr->right;
		i++;
	}
	return (threads);
}

int	main(int argc, char **argv)
{
	int				i;
	pthread_attr_t	attr;
	pthread_t		*threads;

	i = 0;
	if (argc < 5 || argc > 7)
		return (1);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	threads = init_threads(ft_atoi(argv[1]), attr, argv);
	while (i < ft_atoi(argv[1]))
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	pthread_attr_destroy(&attr);
	pthread_exit (NULL);
	return (0);
}
