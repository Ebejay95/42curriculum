/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:19:51 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/27 16:06:56 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief 
/// @param n 
/// @return 
int	ft_putunbrr(unsigned int n)
{
	char	nbr;
	int		r;
	int		wr;
	int		rr;

	r = 0;
	nbr = (n % 10) + '0';
	n = n / 10;
	if (n > 0)
	{
		rr = ft_putnbrr(n);
		if (rr == -1)
			return (-1);
		r = r + rr;
	}
	wr = ft_putchar(nbr);
	if (wr == -1)
		return (-1);
	else
		r = r + wr;
	return (r);
}
