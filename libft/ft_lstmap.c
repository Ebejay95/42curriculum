/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:39:43 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 16:46:15 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*new;

	mapped = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&mapped, del);
			return (NULL);
		}
		if (mapped == NULL)
			mapped = new;
		else
			ft_lstadd_back(&mapped, new);
		lst = lst->next;
	}
	return (mapped);
}
