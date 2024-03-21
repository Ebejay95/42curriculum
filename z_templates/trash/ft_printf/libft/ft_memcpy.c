/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:14:39 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 20:48:19 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief					copy memory range by two pointer and size
/// @algorithm				1)	check the existance of trg and src
///							2)	cast the memory pointers to char as duplicates
///								so reference to original data wont be lost
///								and the data can be copied from trg to src
///							3)	perform copy on each byte in the range by 
///								moving the pointers and writing to thier
///								pointed to values
///							4)	return NULL or the trg initial pointer
/// @param src 				memory copy reference
/// @param trg 				memory to be copied to
/// @param n 				range size to be copied
/// @return trg | NULL		the pointer to trg
void	*ft_memcpy(void *trg, const void *src, size_t size)
{
	char	*work_trg;
	char	*work_src;

	if (trg == NULL && src == NULL)
		return (NULL);
	work_trg = (char *)trg;
	work_src = (char *)src;
	while (size > 0)
	{
		*work_trg = *work_src;
		work_src++;
		work_trg++;
		size--;
	}
	return (trg);
}
