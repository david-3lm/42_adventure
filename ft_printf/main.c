/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:58:11 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/13 15:59:31 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	const void	*ptr = malloc (1);


	ft_printf("Hola buenas: %s Numero: %i Numero mu grande: %u Hex: %X\n",
		NULL, 0, 321424, 30);
	printf("Hola buenas: %s Numero: %i Numero mu grande: %u Hex: %X\n",
		NULL, 0, 321424, 30);
	ft_printf("\n------------PUNTERO----------\n");
	ft_printf("%p\n", ptr);
	printf("%p", ptr);
}
