/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:53:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/18 21:47:40 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_base(char *base)
{
	char	*default_base;

	default_base = "0123456789";
	if (ft_strlen(base) < 2 || !ft_str_is_unique(base))
		return (default_base);
	return (base);
}

static size_t	get_res_len(long int input, size_t base_len)
{
	size_t len;

	len = 0;
	if (input <= 0)
	{
	len = 1;
		input = input * (-1);
	}
	while (input > 0)
	{
		len++;
		input = input / base_len;
	}
	
	return (len);
}

char	*ft_strbase(long long int input, char *base)
{
	char			*result;
	size_t			i;
	size_t			len;
	size_t			base_len;
	long long		input_work;

	base = check_base(base);
	base_len = ft_strlen(base);
	len = get_res_len(input, base_len) + 1;
	if (0 > input)
	{
		input_work = input * (-1);
	}
	else
	{
		input_work = input;
	}
		i = 0;
	result = ft_calloc(len, sizeof(char));
	if (result == NULL)
		return (NULL);
	if (input == 0)
	{
		result[i] = base[0];
		i++;
	}
	while (input_work > 0)
	{
		result[i] = base[input_work % base_len];
		input_work = input_work / base_len;
		i++;
	}
	if (0 > input)
	{
		result[i] = '-';
		i++;
	}
	result[i] = '\0';
	result = ft_strrev(result);
	return (result);
}