/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:12:43 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/18 11:58:38 by dlopez-l         ###   ########.fr       */
=======
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:12:43 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/16 16:25:31 by dlopez-l         ###   ########.fr       */
>>>>>>> 5feaec38ab13f191be588b79c2176c7ec7201bca
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
=======
#include <stdlib.h>
>>>>>>> 5feaec38ab13f191be588b79c2176c7ec7201bca

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*ptr_char;
<<<<<<< HEAD

	ptr = malloc(count * size);
	ptr_char = ptr;
	ft_bzero(ptr, count * size);
=======
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	ptr_char = ptr;
	while (i < count * size)
	{
		ptr_char[i] = 0;
		i++;
	}
>>>>>>> 5feaec38ab13f191be588b79c2176c7ec7201bca
	return (ptr);
}
