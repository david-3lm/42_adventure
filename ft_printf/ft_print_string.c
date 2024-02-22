/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:02:07 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/22 14:49:43 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	size_t			size;
	size_t			i;

	if (!str)
		return (ft_print_string("(null)"));
	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (size);
}
