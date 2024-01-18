/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:37 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/18 11:58:44 by dlopez-l         ###   ########.fr       */
=======
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:29:37 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/16 14:34:14 by dlopez-l         ###   ########.fr       */
>>>>>>> 5feaec38ab13f191be588b79c2176c7ec7201bca
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (*ptr == c)
			return (ptr);
		n--;
	}
	return (0);
}

//Faltan pruebas