/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:34:30 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/14 16:19:48 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_input(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 0)
		return (0);
	if (ft_atoi(argv[2]) < 0)
		return (0);
	if (ft_atoi(argv[3]) < 0)
		return (0);
	if (ft_atoi(argv[4]) < 0)
		return (0);
	if (argc == 6 && ft_atoi(argv[5]) < 0)
		return (0);
	return (1);
}

void	clean_table(t_table *table)
{
	t_table	*curr;
	t_table	*temp;
	int		i;
	int		n;

	i = 0;
	n = table->n_philo;
	curr = table->right;
	free(table->philo->console_m);
	while (i < n)
	{
		if (i < n - 1)
			temp = curr->right;
		free(curr->philo);
		curr->philo = NULL;
		pthread_mutex_destroy(&curr->l_fork->mutex);
		free(curr->l_fork);
		free(curr);
		curr = NULL;
		if (i < n - 1)
			curr = temp;
		i++;
	}
}
