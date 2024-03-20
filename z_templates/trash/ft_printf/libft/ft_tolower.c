/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:51:54 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 17:59:56 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		check a char represented by an int to be uppercase and perform
///				transformation to lowercase on it
/// @algorithm	check the char by ascii range A - Z and modify by adding 32
/// @param c	char represented by an int to check
/// @return		lowercase char represented by an int
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
