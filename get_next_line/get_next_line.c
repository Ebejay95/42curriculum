/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:17 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/27 17:07:24 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*workstring;
	char		*line;
	int			status;

	line = NULL;
	status = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	workstring = build_workstring(fd, workstring, &status);
	if (workstring == NULL || status == -1)
		return (smart_free(workstring, 1));
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

char	*build_workstring(int fd, char *workstring, int *file_open)
{
	char	range[BUFFER_SIZE + 1];
	char	*tmp;

	ft_memset(range, 0, BUFFER_SIZE + 1);
	if (workstring == NULL)
	{
		workstring = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (workstring == NULL)
			return (NULL);
		ft_memset(workstring, 0, BUFFER_SIZE + 1);
	}
	while (*file_open > 0 && !ft_contains(range, '\n'))
	{
		*file_open = read(fd, range, BUFFER_SIZE);
		if (*file_open == -1)
			return (smart_free(workstring, 0));
		if (*file_open == 0)
			break ;
		range[*file_open] = '\0';
		if (workstring == NULL)
			return (NULL);
		tmp = ft_strjoin(workstring, range);
		free(workstring);
		workstring = tmp;
	}
	return (workstring);
}

char	*build_line(char *workstring)
{
	char		*line;
	size_t		linelen;
	size_t		i;

	i = 0;
	linelen = 0;
	if (workstring == NULL || workstring[i] == '\0')
		return (NULL);
	while (workstring[linelen] != '\n' && workstring[linelen] != '\0')
		linelen++;
	if (workstring[linelen] == '\n')
		line = malloc((linelen + 2) * sizeof(char));
	else
		line = malloc((linelen + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (i < linelen)
	{
		line[i] = workstring[i];
		i++;
	}
	if (workstring[linelen] == '\n')
		line[i++] = '\n';
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
		return (NULL);
	while (workstring[i] != '\n' && workstring[i] != '\0')
		i++;
	if (workstring[i] == '\0')
		return (smart_free(workstring, 0));
	i++;
	next = malloc((ft_strlen(workstring) - i + 1) * sizeof(char));
	if (next == NULL)
		return (smart_free(workstring, 0));
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
