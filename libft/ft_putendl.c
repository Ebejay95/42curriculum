/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:20:21 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/15 16:41:29 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		write a string with a newline to the desired file descriptor
///	@algorithm	iterate pointer over the string till null termination is reached
///				print each pointed value to the file descriptor and add a
///				newline at the end
/// @param s 	the string to write
/// @param fd 	the file descriptor
///				0	stdin 	do not use!
///				1	stdout	to console
///				2	stderr	to error log
///				2<	to file in writing status
void	ft_putendl(char *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}
