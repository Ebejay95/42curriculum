/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplaceall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:45:00 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 15:32:29 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*build_res(char	*res, char *h, char *n, char *r)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (h[i] != '\0')
	{
		if (ft_strnstr(&h[i], n, ft_strlen(h) - i))
		{
			ft_memcpy(res + j, r, ft_strlen(r));
			i = i + ft_strlen(n);
			j = j + ft_strlen(r);
		}
		else
			res[j++] = h[i++];
	}
	res[j] = '\0';
	return (res);
}

char	*ft_strreplaceall(char *h, char *n, char *r)
{
	size_t	i;
	size_t	count;
	size_t	len;
	char	*res;

	if (!h || !n || !r)
		return (NULL);
	count = 0;
	i = 0;
	while (h[i] != '\0')
	{
		if (ft_strnstr(&h[i], n, ft_strlen(h) - 1))
		{
			count++;
			i = i + (ft_strlen(n) - 1);
		}
		i++;
	}
	len = ft_strlen(h) + count * (ft_strlen(r) - ft_strlen(n)) + 1;
	res = ft_calloc(len, sizeof(char));
	if (res == NULL)
		return (NULL);
	res = build_res(res, h, n, r);
	return (res);
}
