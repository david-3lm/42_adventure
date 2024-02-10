/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:58:11 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/08 19:29:40 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_printf(char const *format, ...)
{
	va_list			args;
	int				i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char	*c = va_arg(args, char *);
				write(1 , &c, 1);
			}
		}
		i++;
	}
	va_end(args);
	return (1);
}

int	main(void)
{
	ft_printf("%c", "t");
}