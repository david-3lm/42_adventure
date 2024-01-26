/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:02:16 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/26 12:51:18 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*iter(t_list *l, int s, void *(*f)(void *), void (*del)(void *))
{
	int		i;
	t_list	*start;
	t_list	*cpy;
	t_list	*link;

	i = 1;
	cpy = l;
	start = ft_lstnew(cpy->content);
	if (!start)
		return (0);
	link = start;
	while (i < s)
	{
		cpy = cpy->next;
		link->next = ft_lstnew(cpy->content);
		if (!link->next)
			ft_lstclear(&start, del);
		link = link->next;
		link->content = (*f)(link->content);
		i++;
	}
	return (start);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		size;
	int		i;
	t_list	*start;

	size = ft_lstsize(lst);
	i = 0;
	if (!size || !lst)
		return (0);
	start = iter(lst, size, f, del);
	if (!start)
		return (NULL);
	return (start);
}
