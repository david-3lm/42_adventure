/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:40:15 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/02/22 18:19:13 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *buf)
{
	int		i;
	char	*str;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	//sumar 1 si EoF? y 2 para \n y \0???
	str = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(str, buf, i + 1);
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	return (get_line(buffer));
}
