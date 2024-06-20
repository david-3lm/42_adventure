/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:40:15 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/06/20 15:31:13 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*new_buf;
	char	*ptr;
	int		len;

	ptr = ft_strchr(buffer, '\n');
	if (!ptr)
	{
		//new_buf = NULL;
		return (free_mem(&buffer));
	}
	len = (ptr - buffer) + 1;
	if (!buffer[len])
		return (free_mem(&buffer));
	new_buf = ft_substr(buffer, len, ft_strlen(buffer) - len);
	free_mem(&buffer);
	if (!new_buf)
		return (NULL);
	return (new_buf);
}

static char	*get_line(char *buffer)
{
	char	*line;
	char	*end;
	int		len;

	end = ft_strchr(buffer, '\n');
	if (!end)
		len = ft_strlen(buffer);
	else
		len = (end - buffer);
	line = ft_substr(buffer, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*read_file(int fd, char *buffer)
{
	int		rd;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free_mem(&buffer));
	rd = 1;
	while (rd > 0 && !ft_strchr(buf, '\n'))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd > 0)
		{
			buf[rd] = '\0';
			buffer = ft_strjoin(buffer, buf);
		}
	}
	free(buf);
	if (rd == -1)
		return (free_mem(&buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((buffer && (!ft_strchr(buffer, '\n'))) || !buffer)
		buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line)
		return (free_mem(&buffer));
	buffer = cut_buffer(buffer);
	return (line);
}
