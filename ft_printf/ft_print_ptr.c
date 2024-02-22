/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:52:33 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/22 15:32:18 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(size_t ptr)
{
	int	aux;

	if (write(1, "0x", 2) == ERROR)
		return (ERROR);
	if (!ptr)
	{
		aux = write(1, "0", 1);
		if (aux == ERROR)
			return (ERROR);
		return (aux + 2);
	}
	aux = ft_print_hex(ptr, 0);
	if (aux == ERROR)
		return (ERROR);
	return (aux + 2);
}
