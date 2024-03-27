/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:43:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/24 17:58:07 by jonathanebe      ###   ########.fr       */
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
	// while ((line = get_next_line(fd)) != NULL)
	// {
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
		line = get_next_line(fd);
		printf("R: %s\n\n", line);
		free(line);
	// }
	if (close(fd) == -1)
	{
		perror("Fehler beim Schliessen der Datei");
		exit(EXIT_FAILURE);
	}
	
	
	return (0);
}