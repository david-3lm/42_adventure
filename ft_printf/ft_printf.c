/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:00:34 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/08 19:35:20 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *format, ...)
{
	va_list			args;
	int				i;

	va_start(args, format);
	i = va_arg(args, int);
	printf("%d", i);
	i = va_arg(args, int);
	printf("%d", i);

	va_end(args);
	return (1);
}
