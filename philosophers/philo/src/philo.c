/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:17:01 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/12/03 18:47:45 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philo_start(void *params)
{
	t_params	*p;
	
	p = (t_params *)params;
	printf("%d\n", p->time_to_die);
	return (NULL);
}
