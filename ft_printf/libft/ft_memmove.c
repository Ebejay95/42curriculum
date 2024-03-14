/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:39:02 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 21:07:46 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief					copy memory range by two pointer and size and 
///							prevent seg faults
/// @algorithm				1)	check the existance of trg and src ? return NULL
///							2)	cast the memory pointers to char as duplicates
///								so reference to original data wont be lost
///								and the data can be copied from trg to src
///							3)	the data is copied from the side the data is
///								more likely to be damaged by the memmove 
///								writing on it to keep the src safe read from
///								the side that the trg pointer is nearby and 
///								perform the copy
///							4)	when copying in reverse the pointers are set
///								to the end of the memory by size - 1
///							5)	after performing copy poiter to trg is returned
/// @param src 				memory copy reference
/// @param trg 				memory to be copied to
/// @param n 				range size to be copied
/// @return trg | NULL		the pointer to trg
void	*ft_memmove(void *trg, const void *src, size_t size)
{
	char	*work_src;
	char	*work_trg;

	work_src = (char *)src;
	work_trg = (char *)trg;
	if (!trg && !src)
		return (NULL);
	if (work_trg < work_src)
	{
		while (size--)
		{
			*(work_trg++) = *(work_src++);
		}
	}
	else
	{
		work_src = work_src + (size - 1);
		work_trg = work_trg + (size - 1);
		while (size--)
		{
			*(work_trg--) = *(work_src--);
		}
	}
	return (trg);
}
