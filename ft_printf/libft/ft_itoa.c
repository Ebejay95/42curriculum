/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:53:03 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 14:07:05 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/// @brief 			modify the params of ft_itoa
///	@algorithm		1)	declare a int to work with but not lose real int n
///					2)	initialize minus and len and check the minus state by n
///					3)	get the later needed str len by pre processing the 
///						modulo and division operations necessary to get the
///						opportunity to convert int to char by + '0'
/// @param len		len of the string needed for the number
/// @param n		number as int
/// @param minus 	state handler for sign (-)
static void	initialize(int *len, int *n, int *minus)
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

/// @brief 			convert an int to a ascii string representing its written
///					value
///	@algorithm		1)	initialize the len of the string needed for the number
///						as well as an int to store the sign (-) state and the
///						char pointer of the string to be created
///					2)	handle two special cases: 0 and -2147483648 with
///						specific allocation and returning
///					3)	initialize combines the identification of (-) state
///						and the len detection via pointer modification
///					4)	allocate the needed memory for str by len and the
///						minus sign
///					5)	check success of allocation
///					6)	terminate the str in advance on its len
///					7)	set the minus char in advance by its state
///					8)	build the str in reverse order and do the modulo
///						and division operations necessary to get the
///						opportunity to convert int to char by + '0'
///					9)	return the pointer to src
/// @param len		len of the string needed for the number
/// @param n		number as int
/// @param minus 	state handler for sign (-)
///	@return *str	pointer to str
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
	if (minus)
		str[0] = '-';
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
	return (str);
}
