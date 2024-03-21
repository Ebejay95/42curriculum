/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:14:48 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/21 14:49:32 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

/// @brief		get the length of a string
///	@algorithm	decplare an int counter and iterate to the termination of the
///				string str while counting each iteration. return the counter
/// @param str 	string that length shall be returned
/// @return len	length of string
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
