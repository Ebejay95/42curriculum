/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:28:17 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 16:21:17 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief				find a char represented by an int in memory range by a
///						pointer and size
/// @algorithm			1)	cast the memory pointer and char by int to an 
///							unsigned char to prevent comparing negative ascii
///						2)	perform search by comparison on each byte in the
///							range by moving the pointer and return occurance
///							of c as unsigned char
///						3)	return NULL if nothing was found
/// @param s			the pointer to memory
/// @param c			the char represented by an int to be found
/// @param n			the	size of the memory range to search in
/// @return	cs | NULL	the pointer to the location of char or NULL if not found
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*cs;

	uc = (unsigned char) c;
	cs = (unsigned char *) s;
	while (n > 0)
	{
		if (*cs == uc)
			return (cs);
		cs++;
		n--;
	}
	return (NULL);
}
