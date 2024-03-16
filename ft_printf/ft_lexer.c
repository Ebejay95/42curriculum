/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:36:21 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/16 12:25:41 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	filter_not_defined_arg_types(int tc)
{
	if(tc == 99 || tc == 115 || tc == 112 || tc == 100 || tc == 105)
		return (1);
	if(tc == 117 || tc == 120 || tc == 88 || tc == 37)
		return (1);
	return (0);
}

static size_t	get_args_len(const char *text)
{
	size_t 		idx;
	size_t 		len;

	idx = 0;
	len = 0;
	while(text[idx] != '\0')
	{
		if(text[idx] == 37 && text[idx + 1] != '\0')
		{
			if(filter_not_defined_arg_types(text[idx + 1]))
			{
				len++;
				idx++;
			}
		}
		idx++;
	}
	return (len);
}

t_pf_arg	**args_build(t_pf_arg	**arg_array, const char *text, va_list args)
{
	size_t 		arg_idx;
	size_t 		idx;
	t_pf_arg	*new_arg;

	idx = 0;
	arg_idx = 0;
	while(text[idx] != '\0')
	{
		if(text[idx] == 37 && text[idx + 1] != '\0')
		{
			if(filter_not_defined_arg_types(text[idx + 1]))
			{
				new_arg = create_arg(text[idx + 1], idx, args);
				if (new_arg == NULL)
				{
					return (free_args(arg_idx, arg_array));
				}
				else
					arg_array[arg_idx++] = new_arg;
				idx++;
			}
		}
		idx++;
	}
	return (arg_array);
}

t_pf_arg	**lex(const char *text, va_list args)
{
	t_pf_arg	**arg_array;
	size_t	args_len;

	args_len = get_args_len(text);
	arg_array = ft_calloc(args_len, sizeof(t_pf_arg));
	if (arg_array != NULL)
	{
		arg_array = args_build(arg_array, text, args);
	}
	return (arg_array);
}
