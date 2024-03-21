/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:51:51 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 17:59:19 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		check a char represented by an int to be lowercase and perform
///				transformation to uppercase on it
/// @algorithm	check the char by ascii range a - z and modify by subtracting 32
/// @param c	char represented by an int to check
/// @return		uppercase char represented by an int
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
