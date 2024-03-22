/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:19:52 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/22 16:25:07 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief		write a string to the desired file descriptor
///	@algorithm	iterate pointer over the string till null termination is reached
///				print each pointed value to the file descriptor
/// @param s 	the string to write
/// @param fd 	the file descriptor
///				0	stdin 	do not use!
///				1	stdout	to console
///				2	stderr	to error log
///				2<	to file in writing status
int	ft_putstr(char *s)
{
	while (*s != '\0')
	{
		if (write(1, s, 1) < 0)
			return (-1);
		s++;
	}
	return (1);
}
