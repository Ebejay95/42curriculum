/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:17 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/23 19:13:17 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_fragment	*frag;
	char				*line;

	if (fd < 0)
		return (NULL);
	create_line_frags(fd, &frag);
	if (frag == NULL)
		return (NULL);
	line = retreive_line(frag, (retreive_line_len(frag) + 1));
	prepare_next_line(&frag);
	return (line);
}
