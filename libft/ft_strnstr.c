/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:11:21 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/09 15:42:37 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t l)
{
	size_t	n_c;
	size_t	h_c;

	h_c = 0;
	if (n[0] == '\0')
		return ((char *)h);
	while (h[h_c] != '\0' && l > h_c)
	{
		n_c = 0;
		while (n[n_c] != '\0' && l > (h_c + n_c) && n[n_c] == h[h_c + n_c])
		{
			n_c++;
			if (n[n_c] == '\0')
				return ((char *)(&h[h_c]));
		}
		h_c++;
	}
	return (NULL);
}
