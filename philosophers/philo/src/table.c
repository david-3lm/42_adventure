/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:43:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/05 00:08:04 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_table	*init_table(int n_philo)
{
	t_table	*table;
	t_table	*curr;
	int		i;

	i = 0;
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	curr = table;
	while (i < n_philo)
	{
		curr->philo = malloc(sizeof(t_philo));
		if (!curr->philo)
			return (NULL);
		curr->l_fork = init_fork();
		curr->r_fork = init_fork();
		if (!curr->l_fork || !curr->r_fork)
			return (NULL);
		if (i == n_philo - 1)
		{
			curr->right = table;
			table->left = curr;
		}
		else
		{
			curr->right = malloc(sizeof(t_table));
			if (!curr->right)
				return (NULL);
			curr->right->left = curr;
			curr = curr->right;
		}
		i++;
	}
	return (table);
}
