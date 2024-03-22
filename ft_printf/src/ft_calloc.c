/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:03:50 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/22 16:25:07 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief			allocate a defined part of memory by number and size of 
///					items by thier type and fill it with a value of zero
/// @algorithm		1)	initialize a void pointer to work with
///					2)	define the pointer by malloc with the count and size
///					3)	check the success of malloc by if (NULL) condition
///					4)	use memset to fill the allocated memory with zeros
///					5)	return the pointer to the allocated/modified memory
/// @param count 	number of items to allocate
/// @param size 	size of items to allocate
/// @return 		pointer to allocated memory
void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	pointer = ft_memset(pointer, 0, count * size);
	return (pointer);
}
