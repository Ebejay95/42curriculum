/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_unique.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 08:27:42 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/03/27 20:41:20 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief 		check if a strings chars are unique in their occurance
///	@algorithm	walk to trough the str char by char and compare to al likewise
///				running second loop from the position we are courrently
///				reffering
/// @param str 	string to check
/// @return 	1 | 0
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
