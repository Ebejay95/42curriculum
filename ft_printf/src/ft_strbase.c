/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:53:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/27 21:36:29 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief		check the base fur unique chars and min
///				len of 2 chars
/// @param base base to check
/// @return 	valid or not 1 | 0
static int	check_base(const char *base)
{
	if (base == NULL)
		return (0);
	if (ft_strlen(base) < 2 || !ft_str_is_unique((char *)base))
		return (0);
	return (1);
}

/// @brief 			get len of base string result
///	@agorithm		divide input by baselen for next char
///					and count the operations needed till
///					0 is reached = number of later chars needed
/// @param input 	the number to write in the requested base
/// @param base 	the base to use for wrtiting the number
/// @return length	length
static int	get_res_len(unsigned long long input, const char *base)
{
	int	length;

	length = 1;
	while (input != 0)
	{
		input = input / ft_strlen(base);
		length++;
	}
	return (length);
}

/// @brief			make any number to a printable string by base
///	@agorithm		1)	define a res string to hld the result
///						and a len for it to be allocated
///					2)	check the base fur unique chars and min
///						len of 2 chars
///					3)	get the len by get_res_len which imitates
///						the actual writing process:
///					4)	retrieve char from base by modulo input by 
///						base len
///					5)	divide input by baselen for next char
/// @param input 	the number to write in the requested base
/// @param base 	the base to use for wrtiting the number
/// @return	res		string of modified number as printable
char	*ft_strbase(unsigned long long input, const char *base)
{
	char	*res;
	int		len;

	if (!check_base(base))
		return (NULL);
	len = get_res_len(input, base);
	res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	len--;
	if (input == 0)
	{
		res[0] = base[0];
		return (res);
	}
	while (len > 0)
	{
		len--;
		res[len] = base[input % ft_strlen(base)];
		input = input / ft_strlen(base);
	}
	return (res);
}
