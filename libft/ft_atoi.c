/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:25 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/18 11:58:36 by dlopez-l         ###   ########.fr       */
=======
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:25 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/16 15:20:28 by dlopez-l         ###   ########.fr       */
>>>>>>> 5feaec38ab13f191be588b79c2176c7ec7201bca
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
