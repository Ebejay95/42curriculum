/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:42:24 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 10:22:48 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *h, char *n, char *r)
{
	size_t	i;
	char	*res;
	char	*pos;


	pos = ft_strnstr(h, n, ft_strlen(h));
	if (!pos)
		return ft_strdup(h);
	i = pos - h;
	res = ft_calloc(ft_strlen(h) + ft_strlen(r) - ft_strlen(n) + 1, sizeof(char));
	if(res == NULL)
		return (NULL);
	ft_memcpy(res, h, i);
	ft_memcpy(res + i, r, ft_strlen(r));
	ft_memcpy(res + i + ft_strlen(r), h + i + ft_strlen(n), ft_strlen(h) - i - ft_strlen(n));
	return (res);
}
