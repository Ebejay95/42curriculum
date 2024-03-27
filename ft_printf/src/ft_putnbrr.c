/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:10:22 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/27 20:34:39 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief		check the edge cases and modify length tracker and n by ref
///	@algorithm	1)	handle the edge case of 0 and -2147483648
///				3)	handle negative ints by writing - and progress with a
///					positive int for the algorithm to work
/// @param n 	the int to write
/// @param r 	pointer to an int for tracking the length
///	@return r | -1
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

/// @brief		write a int to the desired file descriptor and return the 
///				state of used write functions
///	@algorithm	1)	declare a int to be parsed to write for later writing by
///					ascii addition
///				2)	edgecases are send to case handler and n modified if needed
///					by working on pointer reference the tracking is done here
///				4)	divide int by 10 and parse it to recursion if bigger than 0
///				5)	print the car after the recursion call for right order
///				6)	update r accordingly and return the sum of write state
/// @param n 	the int to write
/// @param r 	pointer to an int for tracking the length
///	@return r | -1
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

/// @brief		write a int to the desired file descriptor and return the 
///				state of used write functions
///	@algorithm	1)	declare r for tracking the printed lenght of all used
///					write calls
///				2)	call the recursive putnbr and return -1 for any write
///					error inside
///				3)	without error return the r as sum of all written char
///					length description
/// @param n 	the int to write
///	@return r | -1
int	ft_putnbrr(int n)
{
	int	r;

	r = 0;
	if (ft_putnbrr_rec(n, &r) == -1)
		return (-1);
	return (r);
}
