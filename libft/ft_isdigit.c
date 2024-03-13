/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:50:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 17:53:10 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		check a char represented by an int to be 0 - 9
/// @algorithm	check the char by ascii range 0 - 9
/// @param c	char represented by an int to check
/// @return		int 1 || 0
int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}
