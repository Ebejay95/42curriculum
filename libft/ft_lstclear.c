/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:08:45 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 14:51:01 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;

	buffer = NULL;
	if (*lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		buffer = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buffer;
	}
}
