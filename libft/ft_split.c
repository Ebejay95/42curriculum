/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:31:19 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/14 07:24:22 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief		count the substrings of s without modifying s in the split
///				function
///	@algorithm	1)	define and initialize a int to count by as well as an i 
///					terator and a variable for thr state toggle
///				2)	walk trough s till the termination while searching for c
///					till a substring (something not c) is found. toggle 
///					state and count a subtring if a character not c occurs
///					and the state has been in the "gap" mode. check in that
///					condition aswell to be not the last position before s
///					terminates
///				3)	return the count of determined substrings
/// @param s	the string analyze
/// @param c 	the char to count splits by
/// @return 	number of splits of s by c
size_t	count_substrs(char const *s, char c)
{
	size_t	count;
	int		i;
	int		state;

	state = 1;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (c != s[i] && state == 1)
			state = 0;
		if ((c == s[i] || s[i + 1] == '\0') && state == 0)
		{
			state = 1;
			count++;
		}
		i++;
	}
	return (count);
}

/// @brief 						allocate and return the stored substr by
///								its length and relative position in s
///	@algorithm					1)	set a substr char pointer for the result
///									and a substr index for a relative copy
///									process that is initialized by 0
///								2)	allocate the memory for substr by the 
///									length from relative end - start
///								3)	check allocation success else return NULL
///									which would result in clear function to 
///									be run
///								4)	perform a realtive copying process from s
///									to substr
///								5)	terminate and return substr
/// @param substr_rel_start 	the relative start of substring in s
/// @param substr_rel_end 		the relative end s[i] of substring in s
/// @param s 					the src str
/// @return 
char	*build_substr(int substr_rel_start, int substr_rel_end, const char *s)
{
	int		substr_idx;
	char	*substr;

	substr_idx = 0;
	substr = ft_calloc((substr_rel_end - substr_rel_start) + 1, sizeof(char));
	if (!substr)
		return (NULL);
	while (substr_idx < (substr_rel_end - substr_rel_start))
	{
		substr[substr_idx] = s[substr_rel_start + substr_idx];
		substr_idx++;
	}
	substr[substr_idx] = '\0';
	return (substr);
}

/// @brief 				provide complete free'ing and dereferencing on
///						allocation errors
///	@algorithm			reverse iterate trough substrs array and free each 
///						alread allocated and stored substring
///						free the substr array itself
/// @param substr_idx 	current substring index
///	@param substrs 		reference to pointer that holds all substrings
/// @return NULL		substrs pointers is destroyed
char	**ft_split_clear_all(int substr_idx, char **substrs)
{
	while (substr_idx > 0)
	{
		substr_idx--;
		free(substrs[substr_idx]);
	}
	free(substrs);
	return (NULL);
}

/// @brief 					provide the logic to retreive substrings from s by c
///	@algorithm				1)	define index for iterating s, a tracker for the
///								length of each substring and a substring start
///								variable to track the realtive position and
///								length of each substring
///							2)	walk trough s till the termination (first while)
///								searching for c (first inner while) till a 
///								substring something not c) is found or s 
///								terminates
///							3)	set that not c occurance as a relative start of
///								the substring
///							4)	proceed iterating s for all char in that are
///								not c and belong to the substring
///								NOTE:	the difference of i and substr_rel_start
///										is the length of the substring and 
///										may be used for its memory allocation
///							5)	check if this difference is not equality and
///								try to create a subtring by allocation at the
///								substring inde of array substrings
///							6)	check allocation success and clear if allocation
///								failed -> the whole substrs array needs to be
///								free'd in that case so NULL will be returned
///							7)	increment substr index
///							8)	return the substrs array if finished and no
///								allocation failed
/// @param s				the string to split
/// @param c 				the char to split string s by
///	@param substrs 			reference to pointer that the results be stored in
/// @return substrs	| NULL	pointer to substrings or NULL if allocation failed
char	**build_substrs(char const *s, char c, char **substrs)
{
	int	i;
	int	substr_idx;
	int	substr_rel_start;

	i = 0;
	substr_idx = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		substr_rel_start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (substr_rel_start != i)
		{
			substrs[substr_idx] = build_substr(substr_rel_start, i, s);
			if (!substrs[substr_idx])
				return (ft_split_clear_all(substr_idx, substrs));
			substr_idx++;
		}
	}
	return (substrs);
}

/// @brief 		split a string s into substrings by a separating char c
///	@algoritm	1)	define a pointer to pointers to char for the result
///					and cast c into unsigned char for robust ascii comparison
///				2)	determine the number of splits
///				3)	allocate memory for the number of splits in pointer char 
///					size to store enough pointers for all the substrings
///				4)	check the success of the allocation or return NULL
///				5)	proceed retreiving the substrings of s for return
/// @param s	the string to split
/// @param c 	the char to split string s by
/// @return 	pointer to pointers to subtrings of s, split by the char c
char	**ft_split(char const *s, char c)
{
	char			**substrs;
	unsigned char	cc;

	cc = (unsigned char)c;
	substrs = ft_calloc(count_substrs(s, cc) + 1, sizeof(char *));
	if (substrs == NULL)
		return (NULL);
	return (build_substrs(s, cc, substrs));
}
