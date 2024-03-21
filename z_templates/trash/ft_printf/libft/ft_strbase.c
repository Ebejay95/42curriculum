/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:53:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 15:33:40 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *base)
{
	if (ft_strlen(base) < 2 || !ft_str_is_unique(base))
		return (0);
	return (1);
}

static size_t	get_res_len(long int input, size_t base_len)
{
	size_t	len;

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

char	*build_base_str(char *result, long long int i, long long i_w, char *b)
{
	size_t			c;

	c = 0;
	if (i == 0)
	{
		result[c] = b[0];
		i++;
	}
	while (i_w > 0)
	{
		result[i] = b[i_w % ft_strlen(b)];
		i_w = i_w / ft_strlen(b);
		i++;
	}
	if (0 > i)
	{
		result[c] = '-';
		i++;
	}
	result[c] = '\0';
	return (result);
}

char	*ft_strbase(long long int input, char *base)
{
	char			*result;
	size_t			len;
	long long		input_work;

	if (!check_base(base))
		return (NULL);
	len = get_res_len(input, ft_strlen(base)) + 1;
	if (0 > input)
		input_work = input * (-1);
	else
		input_work = input;
	result = ft_calloc(len, sizeof(char));
	if (result == NULL)
		return (NULL);
	return (ft_strrev(build_base_str(result, input, input_work, base)));
}
