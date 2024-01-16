/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:58:40 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/12 18:23:17 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize < 0)
		return (0);
	while (src[i])
	{
		if (dstsize && i < dstsize - 1)
			dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
