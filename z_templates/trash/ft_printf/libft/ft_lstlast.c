/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:05:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 12:34:39 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief			get a pointer to the last element in a linked list
/// @algorithm		1)	while the next of each node in the list is not NULL so
///						the end of the lst has not been reached it will be moved
///						to each node and reference the last node
///					2)	return that node
/// @param lst		the linked list
///	@return lst 	pointer to the last element in list lst
t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
