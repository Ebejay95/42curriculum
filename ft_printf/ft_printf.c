/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:32:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 10:18:46 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// USE A F****** PRINT BASE FUNCTION MODIFY PUTSTR

void	ft_printf(const char *text, ...)
{
	va_list		args;
	t_pf_arg	**args_array;
	size_t		args_len;

	args_len = 0;
	va_start(args, text);
	args_array = lex(text, args, &args_len);
	ft_putendl(genstring(text, args_array, args_len));
	va_end(args);
}

int	main ()
{
	ft_printf("Teste %c ", 424);
	ft_printf("Teste %c Teste %s", 42, "42");
	ft_printf("Teste %c Teste %s Teste %p ", 42, "42", 42);
	ft_printf("Teste %c Teste %s Teste %p Teste %d", 42, "42", 42, 42);
	ft_printf("Teste %c Teste %s Teste %p Teste %d Teste %i", 42, "42", 42, 42, 42);
	ft_printf("Teste %c Teste %s Teste %p Teste %d Teste %i Teste %u", 42, "42", 42, 42, 42, 42);
	ft_printf("Teste %c Teste %s Teste %p Teste %d Teste %i Teste %u Teste %x ", 42, "42", 42, 42, 42, 42, 42);
	ft_printf("Teste %c Teste %s Teste %p Teste %d Teste %i Teste %u Teste %x Teste %X", 42, "42", 42, 42, 42, 42, 42, 42);
	ft_printf("Teste %c Teste %s Teste %p Teste %d Teste %i Teste %u Teste %x Teste %X Teste %% ", 42, "42", 42, 42, 42, 42, 42, 42, 42);
    ft_putendl(ft_strbase(5, "01"));
    ft_putendl(ft_strbase(255, "0123456789ABCDEF"));
	return (0);
}