/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:11:05 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/01/16 12:43:59 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_isalpha(int c)
{
	if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	aux;

	aux = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		return (-1);
	else
	{
		if (*nptr == '+')
			nptr++;
	}
	if (!ft_isdigit(*nptr))
		return (-1);
	while (ft_isdigit(*nptr))
	{
		aux = aux * 10 + (*nptr - '0');
		nptr++;
	}
	if (ft_isalpha(*nptr))
		return (-1);
	return (aux);
}
