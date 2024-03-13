/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:14:41 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 20:46:08 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief					compare memory range by two pointer and size
/// @algorithm				1)	cast the memory pointers and the references
///								chars to unsigned char to prevent comparing
///								negative ascii
///							2)	perform search by comparison on each byte in
///								the range by moving the pointers and return
///								occurance of differences c as the difference
///							3)	return NULL if nothing was found
/// @param s1 				memory comparison reference
/// @param s2 				memory to be compared
/// @param n 				range size to be compared
/// @return us1 - us2 | 0	the difference in decimal ascii numbers	
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char			*cs1;
	char			*cs2;
	unsigned char	us1;
	unsigned char	us2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	while (n > 0)
	{
		us1 = (unsigned char)*cs1;
		us2 = (unsigned char)*cs2;
		if (us1 != us2)
			return (us1 - us2);
		n--;
		cs1++;
		cs2++;
	}
	return (0);
}
