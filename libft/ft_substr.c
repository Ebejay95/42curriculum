/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:57:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/11 21:51:04 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// by setting len to the subtraction of ft_strlen(s) - 
// start the value flips to a positive but in any case smaller number than the 
// humongous values may be inserted

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*part;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (length < start + len || len > length - start)
		len = length - start;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	part = (char *)malloc((len + 1) * sizeof(char));
	if (!part)
		return (NULL);
	s = s + start;
	ft_strlcpy(part, s, (len + 1));
	return (part);
}
