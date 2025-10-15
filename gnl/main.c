/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:48:18 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/10/10 18:45:13 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("prueba", O_RDONLY);
	int fd2 = open("prueba2", O_RDONLY);
	char *line;

	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd2));

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s",line);
	}
}