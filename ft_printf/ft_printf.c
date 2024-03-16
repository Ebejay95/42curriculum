/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:32:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/16 15:52:26 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// USE A F****** PRINT BASE FUNCTION MODIFY PUTSTR

void	ft_printf(const char *text, ...)
{
	va_list		args;
	t_pf_arg	**args_array;

	va_start(args, text);
	args_array = lex(text, args);
	// put_strendl(genstring(args_array));
	va_end(args);
}

int	main ()
{
	//ft_printf("Teste sich %X wer kann!", 42);
	ft_putstr(strbase());
	return (0);
}