/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:02:16 by dlopez-l          #+#    #+#             */
/*   Updated: 2024/01/26 17:27:41 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*aux;

	start = ft_lstnew(f((lst)->content));
	if (!start)
		return (0);
	aux = start;
	lst = lst->next;
	while (lst)
	{
		aux->next = ft_lstnew(f((lst)->content));
		if (!aux->next)
		{
			ft_lstclear(&aux, del);
			return (0);
		}
		aux = aux->next;
		lst = lst->next;
	}
	return (start);
}
