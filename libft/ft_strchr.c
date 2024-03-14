/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:09:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 09:35:52 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 					find char in string and return pointer to that char
///	@algorithm				1)	cast s and c to unsigend char for robust ascii
///								comparison.
///							2)	iterate over the casted s cs till termination
///								to find casted c cc return the char pointer to s
///								at that position if found
///							3)	check if the cc is the null terminator that 
///								was not checked by the while yet and point to it
///							4)	return NULL if no occurance was found
/// @param s				the string to search
/// @param c 				the char to search for
/// @return *csrc | NULL	pointer to found occurance of c in s or NULL
char	*ft_strchr(const char *s, int c)
{
	unsigned char	*cs;
	unsigned char	cc;

	cc = (unsigned char)c;
	cs = (unsigned char *)s;
	while (*cs != '\0')
	{
		if (cc == *cs)
			return ((char *)cs);
		cs++;
	}
	if (cc == '\0')
		return ((char *)cs);
	return (NULL);
}
