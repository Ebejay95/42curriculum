/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:31:19 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/12 13:12:56 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t 	count_splits(char const *str, char c)
{
	size_t 	count;
	int 	i;

	count = 0;
	i = 0;
	if(*str == '\0')
		return(0);
    while (str[i] == c)
        i++;
	if(str[0] != c)
		count++;
	while (str[i] != '\0')
	{
		if(c == str[i] && c != str[i + 1] &&  str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}


char **ft_split(char const *s, char c)
{
	size_t	splitters_size;
	char	**splitters;
	int		i;
	int		substr;

	i = 0;
	splitters_size = count_splits(s, c);
	splitters = ft_calloc(splitters_size + 1, sizeof(char *));
	if(splitters == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		substr = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		// Aus der differenz hier mache eine tugend und allociere differenz mit NULL check
		//kopiere mit indize zusaätlzich in spliiters und terminiere mit null. nutze einen anderen index für splitters
	}
	return (splitters);
}
