/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:29:55 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/23 19:55:44 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	frags_complete(t_fragment *frag)
{
	int	strndx;

	while (frag != NULL)
	{
		strndx = 0;
		while (frag->content[strndx] != '\0')
		{
			if (frag->content[strndx] == '\n')
				return (1);
			strndx++;
		}
		frag = frag->next;
	}
	return (0);
}

int	retreive_line_len(t_fragment *frag)
{
	int	line_len;
	int	frag_len;

	line_len = 0;
	if (frag == NULL)
		return (line_len);
	while (frag != NULL)
	{
		frag_len = 0;
		while (frag->content[frag_len] != '\0')
		{
			frag_len++;
			line_len++;
		}
		frag = frag->next;
	}
	return (line_len);
}


void	add_frag(t_fragment **lst, t_fragment *new)
{
	t_fragment	*work;

	work = *lst;
	if (new == NULL)
		return ;
	if (work == NULL)
	{
		*lst = new;
		return ;
	}
	while (work->next != NULL)
		work = work->next;
	work->next = new;
}

void	create_line_frags(int fd, t_fragment	**frag)
{
	char		*read_range;
	int			read_state;
	t_fragment	*new_frag;

	while (!frags_complete(*frag))
	{
		read_range = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (read_range == NULL)
			return ;
		read_state = read(fd, read_range, BUFFER_SIZE);
		if (read_state <= 0)
		{
			free(read_range);
			return ;
		}
		read_range[read_state] = '\0';
		new_frag = malloc(sizeof(t_fragment));
		if (new_frag == NULL)
		{
			free(read_range);
			return ;
		}
		new_frag->content = read_range;
		new_frag->next = NULL;
		add_frag(frag, new_frag);
	}
}

char	*retreive_line(t_fragment *frag, int len)
{
	char	*line;
	int		linendx;
	int		strndx;

	linendx = 0;
	line = malloc(len * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (frag != NULL)
	{
		strndx = 0;
		while (frag->content[strndx] != '\0' && frag->content[strndx] != '\n')
		{
			line[linendx] = frag->content[strndx];
			linendx++;
			strndx++;
		}
		frag = frag->next;
	}
	line[linendx] = '\0';
	return (line);
}

void	prepare_next_line(t_fragment **frag)
{
	t_fragment	*frag_work;
	char		*parse;
	int			idx;
	char		*substrstart;

	frag_work = *frag;
	while (frag_work != NULL)
	{
		idx = 0;
		while (frag_work->content[idx] != '\0' && frag_work->content[idx] != '\n')
			idx++;
		if (frag_work->content[idx] == '\n')
		{
			substrstart = frag_work->content + idx + 1;
			parse = malloc(ft_strlen(substrstart) + 1);
			if(parse == NULL)
				return ;
			ft_strcpy(parse, substrstart);
			free(frag_work->content);
			frag_work->content = parse;
			free_processed_frag(frag, frag_work);
		}
		frag_work = frag_work->next;
	}
}

void	free_processed_frag(t_fragment **frag, t_fragment *frag_work)
{
	t_fragment	*buffer;

	if (*frag == NULL)
		return ;
	while (*frag != frag_work)
	{
		buffer = (*frag)->next;
		free((*frag)->content);
		free(*frag);
		*frag = buffer;
	}
}

void	free_frag(t_fragment **frag)
{
	t_fragment	*buffer;

	if (*frag == NULL)
		return ;
	while (*frag != NULL)
	{
		buffer = (*frag)->next;
		free((*frag)->content);
		free(*frag);
		*frag = buffer;
	}
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
size_t	ft_strcpy(char *trg, const char *src)
{
	size_t	len;

	src = (char *)src;
	len = ft_strlen(src);
	while (*src != '\0')
	{
		*trg = *src;
		src++;
		trg++;
	}
	*trg = '\0';
	return (len);
}