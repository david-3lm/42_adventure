/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:13:02 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/17 16:13:02 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_first_char(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (check_char(s1[i], set))
		i++;
	return (i);
}

static int	get_last_char(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (check_char(s1[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	int		i;
	char	*trim;

	first = get_first_char(s1, set);
	last = get_last_char(s1, set);
	trim = malloc(last - first);
	if (!trim)
		return (0);
	i = 0;
	while (first + i <= last)
	{
		trim[i] = s1[first + i];
		i++;
	}
	return (trim);
}
