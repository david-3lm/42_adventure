/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:58:11 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/13 14:46:19 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("Hola buenas: %s Numero: %i que onda Numero mu grande: %u\n",
		"Como estamos", -65, 4294967294);
	printf("Hola buenas: %s Numero: %i que onda Numero mu grande: %u\n",
		"Como estamos", -65, 4294967294);
}
