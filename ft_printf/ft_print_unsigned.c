/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:32:14 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/13 14:47:52 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_size(int nbr)
{
	int	size;

	size = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

static void	ft_putunsigned_nbr(unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putunsigned_nbr(n / 10);
		ft_putunsigned_nbr(n % 10);
	}
}

int	ft_print_unsigned(unsigned int nbr)
{
	ft_putunsigned_nbr(nbr);
	return (get_size(nbr));
}
