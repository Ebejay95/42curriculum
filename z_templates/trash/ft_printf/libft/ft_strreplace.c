/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:42:24 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 15:29:11 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *h, char *n, char *r)
{
	size_t	i;
	size_t	cp_len;
	size_t	mlen;
	char	*res;
	char	*pos;

	if (!h || !n || !r)
		return (NULL);
	pos = ft_strnstr(h, n, ft_strlen(h));
	if (!pos)
		return (ft_strdup(h));
	i = pos - h;
	mlen = ft_strlen(h) + ft_strlen(r) - ft_strlen(n) + 1;
	res = ft_calloc(mlen, sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, h, i);
	ft_memcpy(res + i, r, ft_strlen(r));
	cp_len = ft_strlen(h) - i - ft_strlen(n);
	ft_memcpy(res + i + ft_strlen(r), h + i + ft_strlen(n), cp_len);
	return (res);
}
