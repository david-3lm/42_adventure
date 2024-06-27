/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:48:09 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/06/27 13:13:18 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*

However, there are a few potential issues:

There is no check to see if BUFFER_SIZE is greater than 0. If it's not, malloc() could fail or read() could behave unexpectedly.

This code assumes that read() will never return 0, which means it may hang indefinitely if the end of the file is reached.

If BUFFER_SIZE is larger than the actual file size, read() will return a smaller number than BUFFER_SIZE, and buf[rd] = '\0'; could cause a segfault.

There's no check to see if ft_strjoin() fails and returns NULL, which would then be passed to ft_strchr() and cause a segfault.

The cut_buffer() function assumes that the newline character will always be followed by at least one more character. If the newline is the last character in the buffer, buffer[len] will be out of bounds and could cause a segfault.

If ft_substr() fails in get_line(), it returns NULL which is then returned by get_line(). But get_next_line() treats this as an error and frees buffer, which may not be desirable.*/

//EN 42 CAMBIAR INTS POR SIZE_T
int main(void)
{

	int fd = open("prueba", O_RDONLY);
	char *line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);  // Libera la memoria asignada para la línea
        line = get_next_line(fd);
    }

	printf("\n%s", line);

}