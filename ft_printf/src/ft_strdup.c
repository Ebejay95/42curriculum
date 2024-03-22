/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:30:41 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/22 16:25:07 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief					copy a string to a new location
///	@algorithm				1)	declare a new char pointer for the result
///							2)	allocate memory by the length of s + 1 for 
///								termination
///							3)	check allocation success else return NULL
///							4)	copy s to cpy
/// @param s				the src string
/// @return cpy | NULL		the copy of the string at new pointer or NULL on
///							allocation error
char	*ft_strdup(const char *s)
{
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s, (ft_strlen(s) + 1));
	return (cpy);
}
