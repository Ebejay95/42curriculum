/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:53:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/22 16:25:07 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

static int	check_base(const char *base)
{
	if (base == NULL)
		return (0);
	if (ft_strlen(base) < 2 || !ft_str_is_unique((char *)base))
		return (0);
	return (1);
}

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
