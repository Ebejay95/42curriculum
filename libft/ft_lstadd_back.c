/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:19:34 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 12:51:05 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	{
		work = work->next;
	}
	work->next = new;
}
