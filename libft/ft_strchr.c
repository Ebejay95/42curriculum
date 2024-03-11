/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:09:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/08 22:02:13 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	unsigned char	*csrc;
	unsigned char	cc;

	cc = (unsigned char)c;
	csrc = (unsigned char *)src;
	while (*csrc != '\0')
	{
		if (cc == *csrc)
			return ((char *)csrc);
		csrc++;
	}
	if (cc == '\0')
		return ((char *)csrc);
	return (NULL);
}
