/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:14:41 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/09 14:00:04 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char			*cs1;
	char			*cs2;
	unsigned char	us1;
	unsigned char	us2;

	cs1 = (char *)s1;
	cs2 = (char *)s2;
	while (n > 0)
	{
		us1 = (unsigned char)*cs1;
		us2 = (unsigned char)*cs2;
		if (us1 != us2)
			return (us1 - us2);
		n--;
		cs1++;
		cs2++;
	}
	return (0);
}
