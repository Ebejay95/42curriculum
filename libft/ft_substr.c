/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:57:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 18:23:52 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 			get a part of s string by the start realtive to the strings
///					initial pointer and a size realtive to this start postition	
///	@algorithm		1)	define a char pointer part to store the return in
///						as well as the src string length
///					2)	check if the src string exists and set the length
///						variable to the length to the src string
///					3)	if start is greater than the length of the src string
///						it would be out of bound and we would return an empty
///						string
///					4)	check if the requested partial is possible in the
///						length of src by making shure the sum of start and len
///						is smaller than the length of src and len is not
///						greater than length - start what represents the
///						existend chars in the src string after start
///						in a case of overflow len is shortened to that
///						size: length - start to prevent seg faults
///					5)	len can now be used safely to allocate memory for part
///					6)	the succes of the allocation is checked
///					7)	the s pointer is set to start's position
///					8)	from that src is copied to part while termination is
///						provided by strlcpy with len + 1
/// @param s 		the src string
/// @param start	position to start copying from relative to the src pointer
/// @param len		range to copy relative to the start
/// @return	part	pointer to the copied sting partial
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*part;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (len > length - start)
		len = length - start;
	part = (char *)malloc((len + 1) * sizeof(char));
	if (!part)
		return (NULL);
	s = s + start;
	ft_strlcpy(part, s, (len + 1));
	return (part);
}
