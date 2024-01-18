/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:12:43 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/18 11:58:38 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*ptr_char;

	ptr = malloc(count * size);
	ptr_char = ptr;
	ft_bzero(ptr, count * size);
	return (ptr);
}
