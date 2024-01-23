/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:53 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/23 12:55:39 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	while (*big && ft_strlen(little) < len)
	{
		i = 0;
		while (big[i] == little[i] && little[i])
			i++;
		if (big[i] == little[i] || !little[i] || i >= len - 1)
			return ((char *)big);
		big++;
	}
	return (0);
}
