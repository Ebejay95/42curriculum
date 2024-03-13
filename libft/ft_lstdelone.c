/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:56:36 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 19:39:55 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		delete a node of a linked list
/// @algorithm	1)	check the existence of lst and del
///				2)	delete node with the deletion callback for its content
///					and the free'ing of the associating pointer
/// @param lst	the linked list
/// @param del	the content deletion callback function
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
