/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:53:03 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/12 23:46:42 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	initialize(int *len, int *n, int *minus)
{
	int	n_work;

	*minus = 0;
	*len = 0;
	if (*n < 0)
	{
		*minus = 1;
		*n = *n * (-1);
	}
	n_work = *n;
	while (n_work > 0)
	{
		n_work = n_work / 10;
		(*len)++;
		if (n_work == 0)
			break ;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		minus;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	initialize(&len, &n, &minus);
	str = ft_calloc((len + 1 + minus), sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n > 0)
	{
		if (!minus)
			len--;
		str[len] = (n % 10) + '0';
		n = n / 10;
		if (minus)
			len--;
	}
	if (minus)
		str[0] = '-';
	return (str);
}
