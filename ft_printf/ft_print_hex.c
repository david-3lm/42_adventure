/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:00:26 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/13 16:05:45 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_hex(size_t arg, int cap)
{
	const char	caps[] = "0123456789ABCDEF";
	const char	mins[] = "0123456789abcdef";
	int			count;

	count = 0;
	if (arg < 16)
	{
		if (cap)
			ft_putchar_fd(caps[arg % 16], 1);
		else
			ft_putchar_fd(mins[arg % 16], 1);
		return (1);
	}
	else
	{
		count += ft_print_hex(arg / 16, cap);
		count += ft_print_hex(arg % 16, cap);
	}
	return (count);
}
