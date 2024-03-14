/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:19:29 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 10:17:32 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		concat (not join - cause no allocation takes place) a string
///				safely, without seg faults to another string
///	@algorithm	1)	define size_t's for the lengths of each string and a index
///				2)	get the strlen of src and the length of target by manually
///					counting it here in consideration of the buffer size
///					NOTE:	The buffer size wont apply if a terminator is
///							somewhere next to the trg pointer before its 
///							described end by the size_t param
///							strlcat may not be used with memory allocated by
///							calloc. use malloc and memset before...
///							and the buffer needs to contain enough space for
///							both strings and their condated shared terminator
///				3)	return the needed buffer length if the buffer does not
///					match the predefined conditions
///				4)	perform a relative copy process and keep track of the max
///					size to be copied with space for termination
///				5)	terminate (trg pointer is modified correctly) and return
///					the now copied size without counting the termination
/// @param trg 	the string to be concated to
/// @param src 	the string concated
/// @param size the expected buffer size of the target (not length of dest
///				but the known allocated memory)
/// @return 
size_t	ft_strlcat(char *trg, const char *src, size_t size)
{
	size_t	c;
	size_t	trg_len;
	size_t	src_len;

	c = 0;
	trg_len = 0;
	src_len = ft_strlen(src);
	while (trg[trg_len] != '\0' && (trg_len < size))
		trg_len++;
	if (size <= trg_len)
		return (size + src_len);
	while (src[c] != '\0' && (trg_len + c < size - 1))
	{
		trg[trg_len + c] = src[c];
		c++;
	}
	trg[trg_len + c] = '\0';
	return (trg_len + src_len);
}
