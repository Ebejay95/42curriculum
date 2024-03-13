/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:31:19 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/13 21:26:38 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_splits(char const *str, char c)
{
	size_t	count;
	int		i;
	int		divide;

	divide = 1;
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (c != str[i] && divide == 1)
			divide = 0;
		if ((c == str[i] || str[i + 1] == '\0') && divide == 0)
		{
			divide = 1;
			count++;
		}
		i++;
	}
	return (count);
}

char	*make_splitter(int substr, int i, const char *s)
{
	int		j;
	char	*split;

	j = 0;
	split = ft_calloc((i - substr) + 1, sizeof(char));
	if (!split)
		return (NULL);
	while (j < (i - substr))
	{
		split[j] = s[substr + j];
		j++;
	}
	split[j] = '\0';
	return (split);
}

char	**splits_flush(int splits_c, char **splits)
{
	while (splits_c > 0)
	{
		splits_c--;
		free(splits[splits_c]);
	}
	free(splits);
	return (NULL);
}

char	**handle_splits(char const *s, char c, char **splits)
{
	int	i;
	int	splits_c;
	int	substr;

	i = 0;
	splits_c = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		substr = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (substr != i)
		{
			splits[splits_c] = make_splitter(substr, i, s);
			if (!splits[splits_c])
				return (splits_flush(splits_c, splits));
			splits_c++;
		}
	}
	return (splits);
}

char	**ft_split(char const *s, char c)
{
	char			**splits;
	unsigned char	cc;

	cc = (unsigned char)c;
	splits = ft_calloc(count_splits(s, cc) + 1, sizeof(char *));
	if (splits == NULL)
		return (NULL);
	return (handle_splits(s, cc, splits));
}
