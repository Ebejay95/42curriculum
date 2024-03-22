/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:17 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/22 22:51:35 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 char	*get_line_content(void *buffer, int sizer)
 {
 	char	*res;
 	char	*bufferchar;
 	int		strlen;
 	int		i;
 	int		linestart;

 	if(*line_c)
 		linestart++;
 	strlen = 0;
 	bufferchar = (char *)buffer;
 	while (bufferchar[strlen] != '\0' && bufferchar[strlen] != '\n' && strlen < sizer)
 	{
 		strlen++;
 	}
 	res = malloc((strlen + 1) * sizeof(char));
 	if(res == NULL)
 		return (NULL);
 	i = 0;
 	while (i < strlen)
 	{
 		res[i] = bufferchar[linestart + i];
 		i++;
 	}
 	res[i] = '\0';
 	return (res);
}

char *get_next_line_walk(int fd, size_t size)
{
	char		*buffer;
	char		*res;
	size_t		proof;

	size = size + BUFFERUNIT;
	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
		return (NULL);
	proof = read(fd, buffer, size);
	if(proof < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[proof] = '\0'

// Füge den neuen Inhalt zu accumulated hinzu.
	// Suche nach einem Zeilenumbruch in accumulated.
	// Wenn ein Zeilenumbruch gefunden wird, teile accumulated und bereite für den nächsten Aufruf vor.
	
	free(buffer);
	// Wenn kein Zeilenumbruch gefunden wurde, rufe rekursiv get_next_line_walk erneut auf.
}
char *get_next_line(int fd)
{
	return (get_next_line_walk(fd, 0));
}