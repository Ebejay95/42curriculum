/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:58:10 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/08 14:47:35 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *start, int fill, size_t size)
{
	unsigned char	*work;

	work = start;
	while (size > 0)
	{
		*work = fill;
		work++;
		size--;
	}
	return (start);
}
