/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:39:02 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/08 20:15:42 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *trg, const void *src, size_t size)
{
	char	*work_src;
	char	*work_trg;

	work_src = (char *)src;
	work_trg = (char *)trg;
	if (!trg && !src)
		return (((void *)0));
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
