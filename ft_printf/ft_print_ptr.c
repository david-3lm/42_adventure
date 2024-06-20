/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:52:33 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/06/20 14:58:45 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(size_t ptr)
{
	int	aux;

	if (!ptr)
	{
		aux = write(1, "(nil)", 5);
		if (aux == ERROR)
			return (ERROR);
		return (aux + 2);
	}
	aux = ft_print_hex(ptr, 0);
	if (write(1, "0x", 2) == ERROR)
		return (ERROR);
	if (aux == ERROR)
		return (ERROR);
	return (aux + 2);
}
