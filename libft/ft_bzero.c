/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:44:55 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 17:36:49 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//TODO: put return ; in case of empty input - not a system function behavior
//TODO:	but necessary in later usage of libft
/// @brief 			set a range after a pointer to null terminators by a size
/// @algorithm		iterate over memory from the start pointer till size
///					operations took place and set the value for each pointer
///					to the null terminator
/// @param start 	pointer to start from
/// @param size 	size to edit
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
