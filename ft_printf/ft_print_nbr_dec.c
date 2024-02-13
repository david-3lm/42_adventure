/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:13:44 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/13 14:26:27 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_nbr_dec(int nbr)
{
	int	size;

	ft_putnbr_fd(nbr, 1);
	size = (nbr <= 0);
	while (nbr != 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}
