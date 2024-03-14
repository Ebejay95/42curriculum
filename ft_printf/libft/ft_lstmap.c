/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:39:43 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 18:19:09 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 			delete allocated content and free new lst copy mapped
/// @param mapped	lst copy
/// @param content	content of new node, that nodes allocation failed
/// @param del 		callback to free and delete content of new node
/// @return NULL
static void	*free_new(t_list *mapped, void *content, void (*del)(void *))
{
	del(content);
	ft_lstclear(&mapped, del);
	return (NULL);
}

/// @brief					create a new list mapped from src lst while
///							modifiing or deleting by provided callbacks
/// @algorithm				1)	check the existence of lst and f
///							2)	while the node in the list is not NULL so
///								the end of the lst has not been reached it will
///								be moved to each node and apply process on each
///								node
///							3)	For each node a new node with the modified
///								content by callback f is created
///							4)	the creation involves alloctation and therefor
///								will be checekd for success
///							5)	if allocation didnt work, the whole list copy
///								mapped needs to be free'd by lstclear and NULL
///								is returned
///							6)	if new exists and mapped has no items yet
///								(is NULL) add the first no node by assigning
///								it to be mapped
///							7)	use lstadd_back to add if mapped has nodes
///								already and return pointer to mapped when
///								finished
/// @param lst				the linked list
/// @param f				the callback to be performed
/// @param f				the deletion callback to be performed
///	@return mapped | NULL	pointer to the new or modified linked list
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*new;
	void	*content;

	mapped = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		content = f(lst->content);
		if (content != NULL)
		{
			new = ft_lstnew(content);
			if (new == NULL)
				return (free_new(mapped, content, del));
			if (mapped == NULL)
				mapped = new;
			else
				ft_lstadd_back(&mapped, new);
		}
		lst = lst->next;
	}
	return (mapped);
}
