/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:32:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/18 21:48:49 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// USE A F****** PRINT BASE FUNCTION MODIFY PUTSTR

void	ft_printf(const char *text, ...)
{
	va_list		args;
	//t_pf_arg	**args_array;

	va_start(args, text);
	//args_array = lex(text, args);
	// put_strendl(genstring(args_array));
	va_end(args);
}

int	main ()
{
	//ft_printf("Teste sich %X wer kann!", 42);
	ft_putstr("nein\n");
    ft_putendl(ft_strbase(5, "01")); // Expected output: "101"
    ft_putendl(ft_strbase(255, "0123456789ABCDEF")); // For testing negative input in a standard base
	ft_putstr("nein\n");
	return (0);
}