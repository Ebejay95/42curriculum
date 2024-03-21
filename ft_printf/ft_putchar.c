/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:16:54 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/21 14:49:45 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

/// @brief		write a char to the desired file descriptor
/// @param c 	the char to write
/// @param fd 	the file descriptor
///				0	stdin 	do not use!
///				1	stdout	to console
///				2	stderr	to error log
///				2<	to file in writing status
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
