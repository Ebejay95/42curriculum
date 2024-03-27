/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_prints_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:27:49 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/03/27 16:09:09 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief 
/// @param i 
/// @return 
int	smart_print_u(unsigned int i)
{
	return (ft_putunbrr(i));
}

/// @brief 
/// @param i 
/// @return 
int	smart_print_x(unsigned int i)
{
	char	*s;
	int		rl;

	s = ft_strbase(i, "0123456789abcdef");
	if (s == NULL)
		return (-1);
	if (ft_putstr(s) < 0)
	{
		free(s);
		return (-1);
	}
	rl = ft_strlen(s);
	free(s);
	return (rl);
}

/// @brief 
/// @param i 
/// @return 
int	smart_print_xup(unsigned int i)
{
	char	*s;
	int		rl;

	s = ft_strbase(i, "0123456789ABCDEF");
	if (s == NULL)
		return (-1);
	if (ft_putstr(s) < 0)
	{
		free(s);
		return (-1);
	}
	rl = ft_strlen(s);
	free(s);
	return (rl);
}

/// @brief 
/// @param type 
/// @param args 
/// @return 
int	smart_print(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = smart_print_c(va_arg(args, int));
	else if (type == 's')
		count = smart_print_s(va_arg(args, char *));
	else if (type == 'p')
		count = smart_print_p(va_arg(args, void *));
	else if (type == 'd')
		count = smart_print_d(va_arg(args, int));
	else if (type == 'i')
		count = smart_print_i(va_arg(args, int));
	else if (type == 'u')
		count = smart_print_u(va_arg(args, unsigned int));
	else if (type == 'x')
		count = smart_print_x(va_arg(args, unsigned int));
	else if (type == 'X')
		count = smart_print_xup(va_arg(args, unsigned int));
	else if (type == '%')
		count = smart_print_c('%');
	return (count);
}

/// @brief 
/// @param  
/// @return 
int	null_pointer(void)
{
	if (ft_putstr("0x0") < 0)
		return (-1);
	return (3);
}
