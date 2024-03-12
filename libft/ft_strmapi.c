/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:52:57 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 00:20:50 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	char	*work;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	work = res;
	while (s[i] != '\0')
	{
		*work = f(i, s[i]);
		work++;
		i++;
	}
	*work = '\0';
	return (res);
}
