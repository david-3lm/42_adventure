/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:30:34 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/18 13:40:29 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 1;
	while (s[i])
	{
		if (s[i] == c && in_word)
		{
			count++;
			in_word = 0;
		}
		else if (s[i] != c)
			in_word = 1;
		i++;
	}
	if (in_word)
		count++;
	return (count);
}

static int	idx_next_word(char const *s, char c, int start)
{
	int	i;

	i = start;
	while (s[i] == c)
		i++;
	return (i);
}

static int	size_next_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**pptr;
	int		words;
	int		i;
	int		idx;
	int		size;

	words = count_words(s, c) + 1;
	pptr = malloc(sizeof(char *) * (words));
	i = 0;
	size = 0;
	while (*s == c)
		s++;
	while (i < words)
	{
		idx = idx_next_word(s, c, idx + size);
		size = size_next_word(&s[idx], c);
		pptr[i] = malloc(size + 1);
		ft_strlcpy(pptr[i], &s[idx], (int) size + 1);
		i++;
	}
	return (pptr);
}
