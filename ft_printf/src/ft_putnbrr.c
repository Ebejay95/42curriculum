/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:10:22 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/27 16:06:49 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief 
/// @param n 
/// @param r 
/// @return 
static int	casehandler(int *n, int *r)
{
	int	buf;

	if (*n == -2147483648)
	{
		buf = write(1, "-2", 2);
		if (buf == -1)
			return (-1);
		*r += buf;
		*n = 147483648;
	}
	else if (*n < 0)
	{
		*n = -*n;
		buf = ft_putchar('-');
		if (buf == -1)
			return (-1);
		*r = *r + buf;
	}
	return (0);
}

/// @brief 
/// @param n 
/// @param r 
/// @return 
static int	ft_putnbrr_rec(int n, int *r)
{
	int	buf;

	if (casehandler(&n, r) == -1)
		return (-1);
	if (n >= 10)
	{
		if (ft_putnbrr_rec(n / 10, r) == -1)
			return (-1);
	}
	buf = ft_putchar((n % 10) + '0');
	if (buf == -1)
		return (-1);
	*r = *r + buf;
	return (0);
}

/// @brief 
/// @param n 
/// @return 
int	ft_putnbrr(int n)
{
	int	r;

	r = 0;
	if (ft_putnbrr_rec(n, &r) == -1)
		return (-1);
	return (r);
}
