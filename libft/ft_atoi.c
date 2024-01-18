/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:25 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/18 11:58:36 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	aux;
	int	neg;

	aux = 0;
	while (!ft_isalnum(*nptr) && *nptr != '-')
		nptr++;
	if (*nptr == '-')
	{
		neg = -1;
		nptr++;
	}
	else
		neg = 1;
	if (!ft_isdigit(*nptr))
		return (0);
	aux += (*nptr - '0');
	nptr++;
	while (ft_isdigit(*nptr))
	{
		aux *= 10;
		aux += (*nptr - '0');
		nptr++;
	}
	return (aux * neg);
}
