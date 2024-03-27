/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:17 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/24 22:08:32 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	is_readable(int fd)
{
	if(read(fd,NULL,0) != -1)
		return (1);
	return (0);
}

char *get_next_line(int fd)
{
	static char	*workstring;
	char	*line;

	if (!is_readable(fd))
	{
		if (workstring != NULL)
		{
			free(workstring);
			workstring = NULL;
		}
		return (NULL);	
	}
	if (workstring == NULL)
	{
		workstring = malloc(sizeof(char));
		*workstring = '\0';
	}
	workstring = build_workstring(fd, workstring);
	if (workstring == NULL)
		return (NULL);
	line = build_line(workstring);
	workstring = perp_next(workstring);
	if (workstring != NULL) {
    	free(workstring);
    	workstring = NULL;
	}
	return (line);
}

//char *build_workstring(int fd, char *workstring)
//{
//	char	*range;
//	char	*tmp;
//	int		file_open;
//
//	range = malloc((BUFFER_SIZE + 1) * sizeof(char));
//	if(range == NULL)
//		return (NULL);
//	file_open = read(fd, range, BUFFER_SIZE);
//	while (file_open > 0)
//	{
//		range[file_open] = '\0';
//		tmp = ft_strjoin(workstring, range);
//		if (tmp == NULL)
//		{
//			free(range);
//			free(workstring);
//			return (NULL);
//		}
//		free(workstring);
//		workstring = tmp;
//		if (ft_contains(range, '\n', BUFFER_SIZE))
//		{
//			break;
//		}
//		file_open = read(fd, range, BUFFER_SIZE);
//	}
//	free(range);
//	if (file_open == -1)
//	{
//		free(workstring);
//		return (NULL);
//	}	
//	return (workstring);
//}

char *build_workstring(int fd, char *workstring)
{
	char	*range;
	char	*tmp;
	int		file_open;

	range = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(range == NULL)
		return (NULL);
	file_open = 1;
	while (file_open > 0 && !ft_contains(range, '\n', BUFFER_SIZE))
	{
		file_open = read(fd, range, BUFFER_SIZE);
		if (file_open == -1)
		{
			free(range);
			free(workstring); 
			return (NULL);
		}
		range[file_open] = '\0';
		tmp = ft_strjoin(workstring, range);
		if (tmp == NULL)
		{
			free(range);
			free(workstring); 
			workstring = NULL;
			return (NULL);
		}
		free(workstring);
		workstring = tmp;
	}
	free(range);
	return (workstring);
}

char	*ft_strrchr(const char *src, int c)
{
	int				len;
	unsigned char	cc;
	char			*cstr;

	cc = (unsigned char)c;
	cstr = (char *)src;
	len = ft_strlen(cstr);
	cstr = len + cstr;
	if (cc == '\0')
		return (cstr);
	cstr--;
	while (len > 0)
	{
		if (cc == *cstr)
			return (cstr);
		cstr--;
		len--;
	}
	return (NULL);
}
int	ft_contains(char *haystack, char needle, long long size)
{
	long long i;

	i = 0;
	while (i < size)
	{
		if (haystack[i] == needle)
			return (1);
		i++;
	}
	return (0);
}

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

char	*build_line(char *workstring)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	if(workstring == NULL || ft_strlen(workstring) == 0)
		return (NULL);
	while (workstring[len] != '\n' && workstring[len] != '\0')
		len++;
	line = malloc((len + 2) * sizeof(char));
	if(line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = workstring[i];
		i++;
	}
	if (workstring[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	
	line[i] = '\0';
	return (line);
}

char	*perp_next(char *workstring)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(workstring);
	if (workstring == NULL)
   		return NULL;
	while (i < len && workstring[i] != '\n')
		i++;
	if (i < len)
	{
		i++;
		while (workstring[i + j] != '\0')
		{
			workstring[j] = workstring[i  + j];
			j++;
		}
		workstring[j] = '\0';
	}
	return (workstring);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}