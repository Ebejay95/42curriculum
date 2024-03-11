/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:37:30 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/11 19:22:31 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	ms;

	ms = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			ms++;
		str++;
	}
	if (!ft_isdigit(*str))
		return (0);
	i = 0;
	while (*str != '\0' && ft_isdigit(*str))
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	if (ms % 2 != 0)
		i = (i * (-1));
	return (i);
}
