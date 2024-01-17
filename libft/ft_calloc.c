/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:12:43 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/16 16:25:31 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*ptr_char;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	ptr_char = ptr;
	while (i < count * size)
	{
		ptr_char[i] = 0;
		i++;
	}
	return (ptr);
}
