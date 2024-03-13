/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:27:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 19:05:52 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		add a node to the front of a linked list
///	@algorithm	1)	stop if new or the lst is not defined
///				3)	set the pointer to lst to the next of new and set new to 
///					be pointed to by the initial pointer, so the list is not
///					lost for the process
/// @param lst 	the linked list
/// @param new	the node to be added
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
