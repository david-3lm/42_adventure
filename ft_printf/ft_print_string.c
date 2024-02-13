/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:02:07 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/13 14:18:50 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_string(char *str)
{
	const size_t	size = ft_strlen(str);
	size_t			i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (size);
}
