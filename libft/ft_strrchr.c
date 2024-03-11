/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:09:10 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/09 00:32:28 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int				len;
	unsigned char	cc;
	char			*cstr;

	cc = (unsigned char)c;
	cstr = (char *)src;
	len = ft_strlen(cstr);
	cstr = len + cstr;
	if (cc == '\0')
		return (cstr);
	while (len > 0)
	{
		cstr--;
		if (cc == *cstr)
			return (cstr);
		len--;
	}
	return (NULL);
}
