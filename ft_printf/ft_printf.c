/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:00:34 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/13 14:39:04 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf(char const *format, ...)
{
	va_list			args;
	int				i;
	int				print_len;

	va_start(args, format);
	i = 0;
	print_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				print_len += ft_print_char(va_arg(args, int));
			else if (format[i] == 's')
				print_len += ft_print_string(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				print_len += ft_print_nbr_dec(va_arg(args, int));
			else if (format[i] == 'u')
				print_len += ft_print_unsigned(va_arg(args, unsigned int));
			else if (format[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (1);
}
