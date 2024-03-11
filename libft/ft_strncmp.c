/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:52:21 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/08 22:37:18 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	us1;
	unsigned char	us2;

	us1 = 0;
	us2 = 0;
	while (n > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		us1 = (unsigned char)*s1;
		us2 = (unsigned char)*s2;
		if (us1 != us2)
			return (us1 - us2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
