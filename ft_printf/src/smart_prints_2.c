/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_prints_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:27:49 by jonathanebe       #+#    #+#             */
/*   Updated: 2024/03/27 21:51:32 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../ft_printf.h"

/// @brief 		write a uint to output and return write state
/// @param i 	the uint to be written
/// @return 	the write state
int	smart_print_u(unsigned int i)
{
	return (ft_putunbrr(i));
}

/// @brief 		write a lowercase hexa to output and return write state
/// @param i 	the lowercase hexa to be written
/// @return 	the write state
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

/// @brief 		write a uppercase hexa to output and return write state
/// @param i 	the uppercase hexa to be written
/// @return 	the write state
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

/// @brief 			execute the smart print function callback by type with 
///					its arg
/// @param type 	type of arg
/// @param args 	args array
/// @return 		len printed by callback
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

/// @brief 		print the null pointer case and return length as write state
/// @return 	0x0
int	null_pointer(void)
{
	if (ft_putstr("0x0") < 0)
		return (-1);
	return (3);
}
