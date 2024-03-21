/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:32:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/21 14:41:15 by jeberle          ###   ########.fr       */
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

int	smart_print_c(int c)
{
	ft_putchar(c);
	return (1);
}

int	smart_print_s(char *s)
{
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	ft_putstr(s);
	return (ft_strlen(s));
}

int	smart_print_p(void *p)
{
	unsigned long long int	ptr;
	char					*s;
	int						rl;

	ptr = (unsigned long long int)p;
	if (p == NULL)
	{
		ft_putstr("0x0");
		return (3);
	}
	s = ft_strbase(ptr, "0123456789abcdef");
	if (s == NULL)
		return (0);
	ft_putstr("0x");
	ft_putstr(s);
	rl = ft_strlen(s) + 2;
	free(s);
	return (rl);
}

int	smart_print_d(int i)
{
	return (ft_putnbrr(i));
}

int	smart_print_i(int i)
{
	char	*s;
	int		rl;

	s = ft_itoa(i);
	if (s == NULL)
		return (0);
	ft_putstr(s);
	rl = ft_strlen(s);
	free(s);
	return (rl);
}

int	smart_print_u(unsigned int i)
{
	return (ft_putunbrr(i));
}

int	smart_print_x(unsigned int i)
{
	char	*s;
	int		rl;

	s = ft_strbase(i, "0123456789abcdef");
	if (s == NULL)
		return (0);
	ft_putstr(s);
	rl = ft_strlen(s);
	free(s);
	return (rl);
}

int	smart_print_xup(unsigned int i)
{
	char	*s;
	int		rl;

	s = ft_strbase(i, "0123456789ABCDEF");
	if (s == NULL)
		return (0);
	ft_putstr(s);
	rl = ft_strlen(s);
	free(s);
	return (rl);
}

int	smart_print(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = smart_print_c(va_arg(args, int));
	else if (type == 's')
	{
		count = smart_print_s(va_arg(args, char *));
	}
	else if (type == 'p')
	{
		count = smart_print_p(va_arg(args, void *));
	}
	else if (type == 'd')
	{
		count = smart_print_d(va_arg(args, int));
	}
	else if (type == 'i')
	{
		count = smart_print_i(va_arg(args, int));
	}
	else if (type == 'u')
	{
		count = smart_print_u(va_arg(args, unsigned int));
	}
	else if (type == 'x')
	{
		count = smart_print_x(va_arg(args, unsigned int));
	}
	else if (type == 'X')
	{
		count = smart_print_xup(va_arg(args, unsigned int));
	}
	else if (type == '%')
	{
		count = smart_print_c('%');
	}
	return (count);
}

int	ft_printf(const char *text, ...)
{
	va_list		args;
	size_t		idx;
	int			pr_len;

	idx = 0;
	pr_len = 0;
	va_start(args, text);
	while (text[idx] != '\0')
	{
		if (text[idx] == 37 && text[idx + 1] != '\0')
		{
			if (filter_not_defined_arg_types(text[idx + 1]))
			{
				pr_len = smart_print(text[idx + 1], args) + pr_len;
				idx = idx + 2;
			}
		}
		else
		{
			ft_putchar(text[idx]);
			idx++;
			pr_len++;
		}
	}
	va_end(args);
	return (pr_len);
}
//int main(void)
//{
//	ft_putstr(ft_strbase(-345,"0123456789"));
////// c_tests
//ft_printf("c Test 1: %c\n", '0');
//ft_printf("c Test 2:  %c \n", '0');
//ft_printf("c Test 3:  %c\n", '0' - 256);
//ft_printf("c Test 4: %c \n", '0' + 256);	//	ft_printf("c Test 5:  %c %c %c \n", '0', 0, '1');
//ft_printf("c Test 6:  %c %c %c \n", ' ', ' ', ' ');
//ft_printf("c Test 7:  %c %c %c \n", '1', '2', '3');
//ft_printf("c Test 8:  %c %c %c \n", '2', '1', 0);
//ft_printf("c Test 9:  %c %c %c \n", 0, '1', '2');
//}