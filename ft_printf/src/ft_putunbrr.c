/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:19:51 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/27 20:35:55 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief		write a int to the desired file descriptor and return the 
///				state of used write functions
///	@algorithm	1)	declare r for tracking the printed lenght of all used
///					write calls
///				2)	divide int by 10 and parse it to recursion if bigger than 0
///				3)	print the car after the recursion call for right order
///				4)	without error return the r as sum of all written char
///					length description
/// @param n 	the int to write
///	@return r | -1
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
