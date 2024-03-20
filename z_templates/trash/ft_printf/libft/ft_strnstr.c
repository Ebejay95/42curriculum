/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:11:21 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 07:42:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 			find a position in haystack where the needle string can be
///					found
///	@algorithm		1)	declare indexes for haystack and needle and init the
///						heystack index 0
///					2)	check the edge case that needle is empty so return
///						the pointer to haystack immediatly
///					3)	iterate over haystack till termination or len to check
///						es reached
///					4)	for eah position set needle index to 0 and iterate
///						trough needle as long as the needle matches the heystack
///						compared by realtive positions and the len at heystacks
///						relative length at that point has not been reached
///					5)	if needle manages to reach termination the substring was
///						was found and the haystack position can be returned
///						it has been kept in the outer loop and only the needle
///						index was iterated in the inner loop so it points to
///						the relative start of the successfully checked needle
/// @param hayst	the string to search in
/// @param needle	the string to search for
/// @param len 		the len so search in (for haystack) needle will stick to
/// @return
char	*ft_strnstr(const char *hayst, const char *needle, size_t len)
{
	size_t	n;
	size_t	h;

	h = 0;
	if (needle[0] == '\0')
		return ((char *)hayst);
	while (hayst[h] != '\0' && len > h)
	{
		n = 0;
		while (needle[n] != '\0' && len > (h + n) && needle[n] == hayst[h + n])
		{
			n++;
			if (needle[n] == '\0')
				return ((char *)(&hayst[h]));
		}
		h++;
	}
	return (NULL);
}
