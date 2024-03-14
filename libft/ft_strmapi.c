/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:52:57 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 08:04:59 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		apply a function on each char in a string and crate a new string
///				containing the results
///	@algorithm	1)	declare index, a char pointer for the result and a res copy 
///					to use to keep the beginning of res
///				2)	check s and f are set
///				3)	apply f on each pointer value in while, copy the callbacks
///					result into the working pointer associated with res array
///				4)	set termination and return res
/// @param s 	the src string for manipulated copy
/// @param f	the function to manipulate used as callback
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	char	*work;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	work = res;
	while (s[i] != '\0')
	{
		*work = f(i, s[i]);
		work++;
		i++;
	}
	*work = '\0';
	return (res);
}
