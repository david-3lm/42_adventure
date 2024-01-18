/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:11:47 by dlopez-l          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/18 11:58:59 by dlopez-l         ###   ########.fr       */
=======
/*   Updated: 2024/01/16 16:18:26 by dlopez-l         ###   ########.fr       */
>>>>>>> 5feaec38ab13f191be588b79c2176c7ec7201bca
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}
