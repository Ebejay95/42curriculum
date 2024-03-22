/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:06:07 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/22 16:25:07 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief		check a char represented by an int to be 32 - 126 defined as
///				printable
/// @algorithm	check the char by ascii range 32 - 126
/// @param c	char represented by an int to check
/// @return		int 1 || 0
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
