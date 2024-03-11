/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:28:17 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/09 15:14:16 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*cs;

	uc = (unsigned char) c;
	cs = (unsigned char *) s;
	while (n > 0)
	{
		if (*cs == uc)
			return (cs);
		cs++;
		n--;
	}
	return (NULL);
}
