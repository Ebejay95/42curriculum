/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:37:30 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 14:07:13 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		checks if a char is an char declared as a whitespace character
///				by comparing the ascii int values in their ranges
/// @param c 	the char to check
/// @return 	0 || 1 depending on the char
static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

/// @brief 		provides a int by a string that follows a strict format
/// 			it can contain leading whitespace chars, one sign (+ || -) 
///				and will handle edge cases.
///
///	@algorithm	1)	initialize an int by 0 for later usage
///				2)	walk trough the strings whiltespaces till u find a non 
///					whitespace char
///				2)	check if the non whitespace char is a sign (+ || -)
///					and store the state if minus is set
///				3)	check if the following char is a digit ascii char
///				4)	iterate over the string till a char is not a digit ascii 
///					char and add each char value to the int i multiplied
///					by 10 till u reach the strings termination
///				5)	multiply by -1 if the string had a sign -
///				
/// @param str 
/// @return 	int i || 0
int	ft_atoi(const char *str)
{
	int	i;
	int	ms;

	i = 0;
	ms = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			ms++;
		str++;
	}
	if (!ft_isdigit(*str))
		return (0);
	while (*str != '\0' && ft_isdigit(*str))
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	if (ms % 2 != 0)
		i = (i * (-1));
	return (i);
}
