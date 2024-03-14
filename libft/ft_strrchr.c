/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:09:10 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 07:48:50 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 					find char in string and return pointer to that char
///							and start the scan from end of the string
///	@algorithm				1)	cast c to unsigend char for robust ascii
///								comparison.
///							2)	determine the length of s and store it for
///								reverse iteration over s
///							3)	set the pointer of s to its termination by
///								adding length to inital pointer
///							4)	check if the cc is the null terminator and 
///								point to it decrement pointer once for this
///							2)	reverse iterate over the casted s cs till 
///								len index is 0 to find casted c cc return and
///								the char pointer to s at that position if found
///							4)	return NULL if no occurance was found
/// @param s				the string to search in
/// @param c 				the char to search for
/// @return *csrc | NULL	pointer to reverse found occurance of c in s or NULL
char	*ft_strrchr(const char *src, int c)
{
	int				len;
	unsigned char	cc;
	char			*cstr;

	cc = (unsigned char)c;
	cstr = (char *)src;
	len = ft_strlen(cstr);
	cstr = len + cstr;
	if (cc == '\0')
		return (cstr);
	cstr--;
	while (len > 0)
	{
		if (cc == *cstr)
			return (cstr);
		cstr--;
		len--;
	}
	return (NULL);
}
