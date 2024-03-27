/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:17 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/27 15:36:26 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*workstring;
	char	*line;
	int		status;

	line = NULL;
	status = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);	
	}
	workstring = build_workstring(fd, workstring, &status);
	if (workstring == NULL || status == -1) {
		if(workstring != NULL){
	    	free(workstring);
	    	workstring = NULL;
		}
		return (NULL);
	}
	line = build_line(workstring);
	if (line == NULL)
	{
		free(workstring);
		workstring = NULL;
		return (NULL);
	}
	workstring = prep_next(workstring);
	return (line);
}

char *build_workstring(int fd, char *workstring, int *file_open)
{
	char	range[BUFFER_SIZE + 1];
	char	*tmp;

	ft_memset(range, 0, BUFFER_SIZE + 1);
	if (workstring == NULL)
	{
		workstring = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if(workstring == NULL)
			return (NULL);
		ft_memset(workstring, 0, BUFFER_SIZE + 1);
	}
	while (*file_open > 0 && !ft_contains(range, '\n'))
	{
		*file_open = read(fd, range, BUFFER_SIZE);
		if (*file_open == -1)
		{
			free(workstring);
			return (NULL);
		}
		if (*file_open == 0)
			break;
		range[*file_open] = '\0';
		if(workstring == NULL)
			return (NULL);
		tmp = ft_strjoin(workstring, range); // CHANGW!!!
		free(workstring);
		workstring = tmp;
	}
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
int	ft_contains(char *haystack, char needle)
{
	long long i;

	i = 0;
	if(haystack == NULL)
		return (0);
	while (haystack[i])
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
	char		*line;
	size_t		linelen;
	size_t		i;

	i = 0;
	linelen = 0;
	if(workstring == NULL || workstring[i] == '\0')
		return (NULL);
	while (workstring[linelen] != '\n' && workstring[linelen] != '\0')
		linelen++;
	if (workstring[linelen] == '\n')
		line = malloc((linelen + 2) * sizeof(char));
	else
		line = malloc((linelen + 1) * sizeof(char));
	if(line == NULL)
		return (NULL);
	i = 0;
	while (i < linelen) // TODO pruefen
	{
		line[i] = workstring[i];
		i++;
	}
	if (workstring[linelen] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	
	line[i] = '\0';
	return (line);
}

char	*prep_next(char *workstring)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	if (workstring == NULL)
   		return NULL;
	while (workstring[i] != '\n' && workstring[i] != '\0')
		i++;
	if (workstring[i] == '\0')
	{
		free(workstring);
		return (NULL);
	}
	i++;
	next = malloc((ft_strlen(workstring) - i + 1) * sizeof(char));
	if (next == NULL)
	{
		free(workstring);
		return (NULL);
	}
	while (workstring[i] != '\0')
	{
		next[j] = workstring[i];
		i++;
		j++;
	}
	next[j] = '\0';
	free(workstring);
	return (next);
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
void	*ft_memset(void *start, int fill, size_t size)
{
	unsigned char	*work;

	work = start;
	while (size > 0)
	{
		*work = fill;
		work++;
		size--;
	}
	return (start);
}
