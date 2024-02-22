/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:13:44 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/22 15:25:55 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_nbr(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else
	{
		if (n < 0)
		{
			n *= -1;
			if (write(fd, "-", 1) == -1)
				return (-1);
		}
		if (n <= 9)
		{
			c = n + '0';
			if (write(fd, &c, 1) == -1)
				return (-1);
		}
		else
		{
			if (write_nbr(n / 10, fd) == -1 || write_nbr(n % 10, fd) == -1)
				return (-1);
		}
	}
	return (1);
}

int	ft_print_nbr_dec(int nbr)
{
	int	size;

	if (write_nbr(nbr, 1) == -1)
		return (-1);
	size = (nbr <= 0);
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}
