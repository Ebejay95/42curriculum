/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:03:20 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/12 00:01:00 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(char *haystack, char needle)
{
	while (*haystack != '\0')
	{
		if (*haystack == needle)
			return (1);
		haystack++;
	}
	return (0);
}

static int	ft_pre(char const *s1, char const *set)
{
	int		pre;

	pre = 0;
	while (s1[pre] != '\0' && ft_contains((char *)set, s1[pre]))
		pre++;
	return (pre);
}

static int	ft_suf(char const *s1, char const *set, int pre)
{
	int		suf;

	suf = ft_strlen(s1);
	while (suf > pre && ft_contains((char *)set, s1[suf - 1]))
		suf--;
	return (suf);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		pre;
	int		suf;
	int		len;
	char	*res_s;
	int		c;

	if (!s1 || !set)
		return (NULL);
	pre = ft_pre(s1, set);
	suf = ft_suf(s1, set, pre);
	c = 0;
	len = suf - pre;
	res_s = malloc((len + 1) * sizeof(char));
	if (!res_s)
		return (NULL);
	while (len > c)
	{
		res_s[c] = s1[pre + c];
		c++;
	}
	res_s[len] = '\0';
	return (res_s);
}
