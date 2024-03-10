/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:50:24 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/03/10 22:57:03 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t 	count_splits(char const *str, char c)
{
	size_t 	count;
	int 	i;

	count = 0;
	i = 0;
	if(*str == '\0')
		return(0);
    while (str[i] == c) {
        i++;
	if(str[0] != c)
		count++;
	while (str[i] != '\0')
	{
		if(c == str[i] && c != str[i + 1] &&  str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count),
}


/// @brief 
/// @param str 
/// @param c 
/// @return 
char	**ft_split(char const *str, char c)
{
}