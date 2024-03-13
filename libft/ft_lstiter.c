/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:37:56 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 19:49:57 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		apply a callback function on each node's content of linked list
/// @algorithm	1)	check the existence of lst and f
///				2)	while the node in the list is not NULL so
///					the end of the lst has not been reached it will be moved
///					to each node and apply the f callback for its content
/// @param lst	the linked list
/// @param f	the callback to be performed
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
