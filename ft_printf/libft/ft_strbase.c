/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:53:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 22:06:18 by jonathanebe      ###   ########.fr       */
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
    }
    while (input != 0)
    {
        len++;
        input /= base_len;
    }
    return len;
}

char	*build_base_str(long long int i, char *b, size_t l)
{
	char			*res;
	size_t			index;
	long long int	n;

	res = ft_calloc(l + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (i == 0)
	{
		res[0] = b[0];
		return (res);
	}
	index = l - 1;
	if (i < 0)
		n = -i;
	else
		n = i;
	while (n != 0)
	{
		res[index] = b[n % ft_strlen(b)];
		n = n / ft_strlen(b);
		index--;
	}
	if (i < 0 && ft_strlen(b) == 10)
    {
        res[index] = '-';
    }
	return (res);
}

char	*ft_strbase(long long int input, char *base)
{
	size_t			len;

	if (!check_base(base))
		return (NULL);
	len = get_res_len(input, ft_strlen(base));
	return (build_base_str(input, base, len));
}
