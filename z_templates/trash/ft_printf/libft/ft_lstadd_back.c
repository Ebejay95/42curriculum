/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:19:34 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 18:14:06 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		add a node to the end of a linked list
///	@algorithm	1)	initialize a cpy of lst to work with and not loose the
///					initial lst pointer and define it as such
///				2)	stop if new is not defined
///				3)	define new as the lst if it has been empty before and stop
///				4)	walk to the last defined node of the lst (its next is null)
///					and set its next to new so it will be the new last node
/// @param lst 	the linked list
/// @param new	the node to be added
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*work;

	work = *lst;
	if (new == NULL)
		return ;
	if (work == NULL)
	{
		*lst = new;
		return ;
	}
	while (work->next != NULL)
		work = work->next;
	work->next = new;
}
