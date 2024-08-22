/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:40:10 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/08/22 12:59:10 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

char			*get_next_line(int fd);
char			*free_mem(char **c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_calloc(size_t count, size_t size);
unsigned int	ft_strlen(const char *c);

#endif