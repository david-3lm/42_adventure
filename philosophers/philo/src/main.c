/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:59:07 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/03 16:45:08 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

pthread_t	*init_threads(int n, pthread_attr_t attr, char **argv)
{
	int			i;
	int			*arg;
	pthread_t	*threads;
	t_params	*params;

	i = 0;
	threads = malloc(n * sizeof(pthread_t));
	if (!threads)
		return (NULL);
	while (i < n)
	{
		arg = malloc(sizeof(int));  // Crear una copia única
		if (!arg)
			return (NULL);  // Manejar error de memoria
		*arg = i;
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
