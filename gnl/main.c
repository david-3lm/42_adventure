/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:48:09 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/22 18:19:26 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

//EN 42 CAMBIAR INTS POR SIZE_T
int main(void)
{

	int fd = open("prueba", O_RDONLY);
	printf("%s",get_next_line(fd));
}