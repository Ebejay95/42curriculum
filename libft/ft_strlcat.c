/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:19:29 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/09 12:28:43 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *trg, const char *src, size_t size)
{
	size_t	c;
	size_t	trg_len;
	size_t	src_len;

	c = 0;
	trg_len = 0;
	src_len = ft_strlen(src);
	while (trg[trg_len] != '\0' && (trg_len < size))
		trg_len++;
	if (size <= trg_len)
		return (size + src_len);
	while (src[c] != '\0' && (trg_len + c < size - 1))
	{
		trg[trg_len + c] = src[c];
		c++;
	}
	trg[trg_len + c] = '\0';
	return (trg_len + src_len);
}
