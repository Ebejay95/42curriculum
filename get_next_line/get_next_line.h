/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:30 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/24 16:59:36 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef GNL_H
# define GNL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif



size_t	ft_strlen(const char *str);
char	*ft_strrchr(const char *src, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_contains(char *haystack, char needle, long long size); // Korrigiere die Reihenfolge und stelle sicher, dass diese vor ihrer Nutzung deklariert wird.

char	*get_next_line(int fd);
char	*build_line(char *workstring);
char	*build_workstring(int fd, char *line);
char	*perp_next(char *workstring);
#endif