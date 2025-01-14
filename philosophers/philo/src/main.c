/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:59:07 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/14 16:01:42 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philo(t_philo **philo, char **argv, t_table *table, int i)
{
	(*philo)->idx = i + 1;
	(*philo)->time_to_die = ft_atoi(argv[2]);
	(*philo)->time_to_eat = ft_atoi(argv[3]);
	(*philo)->time_to_sleep = ft_atoi(argv[4]);
	(*philo)->table = table;
	(*philo)->is_dead = 0;
	(*philo)->meals = 0;
	(*philo)->time_last_eat = timestamp();
}

pthread_t	*init_thr(pthread_attr_t attr, char **argv, int c, t_table **t)
{
	int				i;
	t_philo			*philo;
	t_table			*curr;
	pthread_t		*threads;
	int				n;

	i = 0;
	n = ft_atoi(argv[1]);
	if (c == 6)
		*t = init_table(n, ft_atoi(argv[5]));
	else
		*t = init_table(n, -1);
	threads = malloc((n + 1) * sizeof(pthread_t));
	curr = *t;
	while (i < n)
	{
		philo = curr->philo;
		init_philo(&philo, argv, curr, i);
		pthread_create(&threads[i], &attr, philo_start, philo);
		curr = curr->right;
		i++;
	}
	pthread_create(&threads[i], &attr, check_death, *t);
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
	if (argc < 5 || argc > 7 || !check_input(argc, argv))
		return (1);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	threads = init_thr(attr, argv, argc, &table);
	if (!threads)
		return (1);
	while (i < ft_atoi(argv[1]) + 1)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	pthread_mutex_destroy(table->philo->console_m);
	clean_table(table);
	pthread_attr_destroy(&attr);
	free(threads);
	pthread_exit (NULL);
	return (0);
}
