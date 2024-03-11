/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:44:55 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/08 20:35:08 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//TODO: put return ; in case of empty input
void	ft_bzero(void *start, size_t size)
{
	char	*work;

	work = start;
	while (size > 0)
	{
		*work = '\0';
		work++;
		size--;
	}
}
