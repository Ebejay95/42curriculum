/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:31:11 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/11 18:31:15 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *trg, const char *src, size_t size)
{
	char	*src_return;
	size_t	len;

	src_return = (char *)src;
	len = ft_strlen(src_return);
	if (trg == ((void *)0))
		return (0);
	if (size == 0)
		return (len);
	while (*src != '\0' && size-- > 1)
		*(trg++) = *(src++);
	*trg = '\0';
	return (len);
}
