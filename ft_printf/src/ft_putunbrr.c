/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:19:51 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/22 16:25:07 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

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
