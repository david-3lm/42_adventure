/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:40:15 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/06/28 16:56:18 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_mem(char **c)
{
	if (c && *c)
	{
		free(*c);
		*c = NULL;
	}
	return (NULL);
}

static char	*cut_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*extra;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free_mem(&buffer));
	extra = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!extra)
		return (free_mem(&buffer));
	i++;
	while (buffer[i])
	{
		extra[j] = buffer[i];
		i++;
		j++;
	}
	free_mem(&buffer);
	return (extra);
}

static char	*get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*read_line(int fd, char *buffer)
{
	char	*temp;
	int		bytes_read;

	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
		return (free_mem(&buffer));
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free_mem(&temp);
			return (free_mem(&buffer));
		}
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free_mem(&temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[48];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = cut_buffer(buffer[fd]);
	return (line);
}
