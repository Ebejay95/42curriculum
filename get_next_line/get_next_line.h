/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:30 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/23 19:53:39 by jeberle          ###   ########.fr       */
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

typedef struct s_fragment
{
	char				*content;
	struct s_fragment	*next;
} t_fragment;


char *get_next_line(int fd);
int	frags_complete(t_fragment *frag);
int	retreive_line_len(t_fragment *frag);
t_fragment	*frag_new(void *content);
void	add_frag(t_fragment **lst, t_fragment *new);
void	create_line_frags(int fd, t_fragment	**frag);
char	*retreive_line(t_fragment *frag, int len);
void	prepare_next_line(t_fragment **frag);
size_t	ft_strcpy(char *trg, const char *src);
size_t	ft_strlen(const char *str);
void	flush_frags(t_fragment **frag);
void	free_processed_frag(t_fragment **frag, t_fragment *frag_work);
void	free_frag(t_fragment **frag);
#endif