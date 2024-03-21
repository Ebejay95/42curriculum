/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:17 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/21 18:10:58 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line_content(void *buffer, int sizer, int *line_c)
{
	char	*res;
	char	*bufferchar;
	int		strlen;
	int		i;
	int		linestart;

	linestart = *line_c;
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
	*line_c = *line_c + strlen + 1;
	return (res);
}

char *get_next_line(int fd)
{
	static int	line_c;
	void		*buffer;
	char		*res;
	int			sizer;
	int			proof;

	line_c = 0;
	sizer = 999;
	buffer = malloc(sizeof(char) * sizer);
	if (buffer == NULL)
		return (NULL);
	proof = read(fd, buffer, sizer);
	if(proof == -1)
	{
		free(buffer);
		return (NULL);
	}
	res = get_line_content(buffer, sizer, &line_c);
	free(buffer);
	return (res);
}
