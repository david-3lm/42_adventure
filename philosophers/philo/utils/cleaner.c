/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:34:30 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/07 16:06:44 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


void	clean_table(t_table *table)
{
	t_table	*curr;
	int		i;

	i = 0;
	curr = table->right;
	while (i < table->n_philo)
	{
		free(curr->philo);
		curr = curr->right;
		i++;
	}
}
