/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:13:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/18 11:59:02 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (start >= ft_strlen(s))
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	sub = malloc(len);
	if (!sub)
		return (0);
	ft_strlcpy(sub, &s[start], len);
	return (sub);
}
