/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_unique.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 08:27:42 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/03/20 15:19:31 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_unique(char *str)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
