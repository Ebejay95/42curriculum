/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:32:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/22 20:30:17 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	filter_not_defined_arg_types(int tc)
{
	if (tc == 99 || tc == 115 || tc == 112 || tc == 100 || tc == 105)
		return (1);
	if (tc == 117 || tc == 120 || tc == 88 || tc == 37)
		return (1);
	return (0);
}

int	ret_error(va_list args)
{
	va_end(args);
	return (-1);
}

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
