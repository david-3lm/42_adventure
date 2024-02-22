/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:32:14 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/22 14:26:03 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putunsigned_nbr(unsigned int n)
{
	char	c;
	int		count;
	int		aux;

	count = 0;
	if (n <= 9)
	{
		c = n + '0';
		return (write(1, &c, 1));
	}
	else
	{
		aux = ft_putunsigned_nbr(n / 10);
		if (aux == -1)
			return (-1);
		count += aux;
		aux = ft_putunsigned_nbr(n % 10);
		if (aux == -1)
			return (-1);
		count += aux;
	}
	return (count);
}

int	ft_print_unsigned(unsigned int nbr)
{
	return (ft_putunsigned_nbr(nbr));
}
