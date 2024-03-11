/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:14:39 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/08 21:32:17 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
