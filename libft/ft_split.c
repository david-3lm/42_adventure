/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:30:34 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/23 16:45:41 by dlopez-l         ###   ########.fr       */
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
	if (!*s)
		return (count);
	in_word = (*s != c);
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

static void	free_mem(char **pptr, int i)
{
	while (0 <= i)
	{
		free(pptr[i]);
		i--;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**pptr;
	int		words;
	int		i;
	int		idx;
	int		size;

	if (!s)
		return (0);
	words = count_words(s, c) + 1;
	pptr = malloc(sizeof(char *) * (words));
	if (!pptr)
		return (0);
	i = 0;
	idx = 0;
	size = 0;
	while (*s == c)
		s++;
	while (i < words - 1)
	{
		idx = idx_next_word(s, c, idx + size);
		size = size_next_word(&s[idx], c);
		pptr[i] = malloc(size + 1);
		if (!pptr[i])
		{
			free_mem(pptr, i);
			return (0);
		}
		ft_strlcpy(pptr[i], &s[idx], (int) size + 1);
		i++;
	}
	pptr[i] = 0;
	return (pptr);
}
