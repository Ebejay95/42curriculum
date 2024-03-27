/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:32:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/27 22:00:56 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief 		apply only defined args by tyoe descriptions to process
/// @param tc 	typechar
/// @return 	0 | 1 handle or not handle
static int	filter_not_defined_arg_types(int tc)
{
	if (tc == 99 || tc == 115 || tc == 112 || tc == 100 || tc == 105)
		return (1);
	if (tc == 117 || tc == 120 || tc == 88 || tc == 37)
		return (1);
	return (0);
}

/// @brief 		conclusion of return for any fail occurance
/// @param args args array to be free'd
/// @return 	-1
int	ret_error(va_list args)
{
	va_end(args);
	return (-1);
}

/// @brief 			the core functionality gateway to all print functions
/// @param text 	text to wrap the args prints
/// @param args 	args array
/// @return 		write state
int	formatted_print(const char *text, va_list args)
{
	int	prr;

	if (filter_not_defined_arg_types(*text))
	{
		prr = smart_print(*text, args);
		if (prr < 0)
			return (-1);
		return (prr);
	}
	return (0);
}

/// @brief 		walker over the stirng, skip placeholders but retrieve
///				their typchar and start the printing process for args
/// @param text text to wrap the args prints
/// @param args args array
/// @param idx 	index of outer loop 
/// @return 	write state
static int	pr_loop(const char *text, va_list args, size_t *idx)
{
	int	prr;

	if (text[*idx] == 37 && text[*idx + 1] != '\0')
	{
		prr = formatted_print(&text[*idx + 1], args);
		if (prr < 0)
			return (-1);
		*idx = *idx + 2;
	}
	else
	{
		prr = ft_putchar(text[*idx]);
		if (prr < 0)
			return (-1);
		(*idx)++;
	}
	return (prr);
}

/// @brief 		print a text and any type args in format and return
///				write state
/// @param text the text conaining placeholders
/// @param ... 	va_list of args
/// @return 	write state
int	ft_printf(const char *text, ...)
{
	va_list		args;
	size_t		idx;
	int			pr_len;
	int			prr;
	int			error;

	idx = 0;
	error = 0;
	pr_len = 0;
	va_start(args, text);
	while (text[idx] != '\0')
	{
		prr = pr_loop(text, args, &idx);
		if (prr < 0)
			return (ret_error(args));
		pr_len = pr_len + prr;
	}
	if (error < 0)
		return (ret_error(args));
	return (pr_len);
}
