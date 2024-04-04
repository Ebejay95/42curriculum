/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:43:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/28 09:01:15 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main (void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Fehler beim Oeffnen der Datei");
		exit(EXIT_FAILURE);
	}
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	if (close(fd) == -1)
	{
		perror("Fehler beim Schliessen der Datei");
		exit(EXIT_FAILURE);
	}
	
	
	return (0);
}