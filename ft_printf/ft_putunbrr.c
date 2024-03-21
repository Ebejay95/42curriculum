/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:19:51 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/21 14:49:54 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putunbrr(unsigned int n)
{
	char	nbr;
	int		r;

	r = 0;
	nbr = (n % 10) + '0';
	n = n / 10;
	if (n > 0)
		r += ft_putnbrr(n);
	r += write(1, &nbr, 1);
	return (r);
}
