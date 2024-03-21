/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:07:43 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/03/18 21:45:01 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief					copy a string to a new location rev
///	@algorithm				1)	declare a new char pointer for the result
///							2)	allocate memory by the length of s + 1 for 
///								termination
///							3)	check allocation success else return NULL
///							4)	copy s to cpy
/// @param s				the src string
/// @return cpy | NULL		the copy of the string at new pointer or NULL on
///							allocation error
char	*ft_strrev(const char *s)
{
	char	*rev;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	rev = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rev)
		return (NULL);
	rev[len] = '\0';
	while (i < len)
	{
		rev[i] = s[len - i - 1];
		i++;
	}
	return (rev);
}
