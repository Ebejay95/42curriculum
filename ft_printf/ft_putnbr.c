/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:21:10 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/21 14:48:32 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

/// @brief		write a int to the desired file descriptor
///	@algorithm	1)	declare a char to be parsed to write for later writing
///				2)	handle the edge case of 0 and -2147483648
///				3)	handle negative ints by writing - and progress with a
///					positive int for the algorithm to work
///				4)	cast the modulo of 10 from current positive int into a char
///				5)	divide int by 10
///				6)	call the function recursivly but keep the char for writing
///					in a reverse recursive action
/// @param n 	the int to write
/// @param fd 	the file descriptor
///				0	stdin 	do not use!
///				1	stdout	to console
///				2	stderr	to error log
///				2<	to file in writing status
void	ft_putnbr(int n)
{
	char	nbr;

	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		n = n * (-1);
		write(1, "-", 1);
	}
	nbr = (n % 10) + '0';
	n = n / 10;
	if (n > 0)
		ft_putnbr(n);
	write(1, &nbr, 1);
}
