/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:52:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/11 22:01:48 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join;
	char	*join_work;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join_work = join;
	while (*s1 != '\0')
	{
		*join_work = *s1;
		join_work++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*join_work = *s2;
		join_work++;
		s2++;
	}
	*join_work = '\0';
	return (join);
}
