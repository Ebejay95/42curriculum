/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:08:45 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 14:37:30 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		clear a linked list from a node on till its end
/// @algorithm	1)	define a buffer reference to not loose the list during the
///					process
///				2)	check the existence of lst and del
///				3)	while the pointer to the node in the list is not NULL so
///					the end of the lst has not been reached it will be moved
///					to each node and delete it with the deletion callback
///					and the free'ing of the associating pointer
///				4)	the to be deleted nodes next value is stored in the buffer
///					for the next deletion, to not loose the reference to lst
/// @param lst	the linked list
/// @param del	the content deletion callback function
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		buffer = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buffer;
	}
}
