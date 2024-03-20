/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:09:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 18:13:07 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		check a char represented by an int to either A - Z, a - z, 0 - 9
/// @algorithm	check the char by combining ft_isdigit and ft_isalpha by or
/// @param c	char represented by an int to check
/// @return		int 1 || 0
int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
