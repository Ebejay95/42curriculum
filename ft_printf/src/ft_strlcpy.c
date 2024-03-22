/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:31:11 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/22 16:25:07 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief 					copy string range by two char pointer and size
/// @algorithm				1)	check the existance of trg
///							2)	cast the src pointer to char for strlen
///								and get len of src for returns
///							3)	handle the edge case that size may be 0
///								and return len only
///							3)	perform copy on each byte in the range by 
///								moving the pointers and writing to thier
///								pointed to values while keeping track of size
///							4)	terminate and return len
/// @param trg 				the pointer to be copied to
/// @param src 				the src string
/// @param size 			the range to be copied
/// @return len | 0			the length of src or 0 if trg is not defined
size_t	ft_strlcpy(char *trg, const char *src, size_t size)
{
	size_t	len;

	src = (char *)src;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (*src != '\0' && size > 1)
	{
		*trg = *src;
		src++;
		trg++;
		size--;
	}
	*trg = '\0';
	return (len);
}
