/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:59:07 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/07 16:00:48 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

pthread_t	*init_threads(int n, pthread_attr_t attr, char **argv, int argc, t_table *table)
{
	int				i;
	t_philo			*philo;
	t_table			*curr;
	pthread_t		*threads;

	i = 0;
	if (argc == 6)
		table = init_table(n, ft_atoi(argv[5]));
	else
		table = init_table(n, -1);
	threads = malloc((n + 1) * sizeof(pthread_t));
	curr = table;
	while (i < n)
	{
		philo = curr->philo;
		philo->idx = i + 1;
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
		philo->table = curr;
		philo->is_dead = 0;
		philo->meals = 0;
		philo->time_last_eat = timestamp();
		pthread_create(&threads[i], &attr, philo_start, philo);
		curr = curr->right;
		i++;
	}
	pthread_create(&threads[i], &attr, check_death, table);
	return (threads);
}

int	main(int argc, char **argv)
{
	int				i;
	pthread_attr_t	attr;
	pthread_t		*threads;
	t_table			*table;

	i = 0;
	table = NULL;
	if (argc < 5 || argc > 7)
		return (1);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	threads = init_threads(ft_atoi(argv[1]), attr, argv, argc, table);
	while (i < ft_atoi(argv[1]))
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	//clean_table(table);
	pthread_attr_destroy(&attr);
	pthread_exit (NULL);
	return (0);
}
