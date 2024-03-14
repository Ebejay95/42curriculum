/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:56:59 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 20:15:35 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 			create a node for a linked list by its content
/// @algorithm		1)	define a node pointer for the new node
///					2)	allocate the memory for it and check the allocations
///						success
///					2)	set the nodes content to content and the next to NULL
/// @param content 	the content of the node to be created
/// @return node	the created node
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = ft_calloc(sizeof(t_list), 1);
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
