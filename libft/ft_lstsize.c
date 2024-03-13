/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:55:50 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 20:17:19 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief			get the length of a linked list
/// @algorithm		1)	initialize len as 0
///					2)	while the node in the list is not NULL so
///						the end of the lst has not been reached it will be moved
///						to each node and count the moves in len
///					3)	return len
/// @param lst		the linked list
/// @return len		the length of lst
int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
