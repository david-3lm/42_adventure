/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:53 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/18 16:29:31 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	while (*big)
	{
		while (big[i] == little[i] && i < len - 1)
			i++;
		if (big[i] == little[i] || !little[i])
			return ((char *)big);
		i = 0;
		big++;
	}
	return (0);
}
	//Faltan pruebas