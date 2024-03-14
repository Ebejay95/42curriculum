/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:52:21 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 09:13:25 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 					compare to strings in a range
/// @algorithm				1)	cast the string pointers and the references
///								chars to unsigned char to prevent comparing
///								negative ascii
///							2)	perform search by comparison on each char in
///								the range by moving the pointers and return
///								occurance of differences c as the difference
///							3)	return 0 if nothing was found
/// @param s1 				string comparison reference
/// @param s2				string to be compared
/// @param n 				range size to be compared
/// @return  us1 - us2 | 0	the difference in decimal ascii numbers	
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	us1;
	unsigned char	us2;

	us1 = 0;
	us2 = 0;
	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		us1 = (unsigned char)*s1;
		us2 = (unsigned char)*s2;
		if (us1 != us2)
			return (us1 - us2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
