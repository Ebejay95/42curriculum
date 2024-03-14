/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:52:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 13:28:38 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 			join a string to the end of another string and return as new
///	@algorithm		1)	define size_ts for the lengths of both strings as well
///						as a char pointer for the result and a char pointer to
///						keep the pointer to the start of the result
///					2)	get the lengths of bothe strings ans allocate their sum
///						of bytes for the join + 1 for termination
///					3)	check allocation success or return NULL
///					4)	store the join start pointer for return
///					5)	iterate trough s1 and s2 after another to fill the 
///						allocated result
///					6)	terminate the result and return the keept pointer to its
///						start
/// @param s1 		string to join to
/// @param s2 		string to be joined
/// @return join	pointer to the joined result	
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*join_work;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
