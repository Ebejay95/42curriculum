/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:58:10 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/21 14:49:41 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

/// @brief 			set a range of memory to a value by poointer and size 
///	@algorithm		set a working buffer to not loose the pointer to memory
///					iterate trough the range by size, move the pointer and
///					set values pointed at
/// @param start 	pointer to memory range
/// @param fill 	value the memory range shall be filled with
/// @param size 	size of the desired range
/// @return start	pointer to start
void	*ft_memset(void *start, int fill, size_t size)
{
	unsigned char	*work;

	work = start;
	while (size > 0)
	{
		*work = fill;
		work++;
		size--;
	}
	return (start);
}
