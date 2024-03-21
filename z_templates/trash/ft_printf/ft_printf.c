/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:32:58 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 18:28:27 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>


int	ft_printf(const char *text, ...)
{
	va_list		args;
	t_pf_arg	**args_array;
	size_t		args_len;
	char		*pr;
	int			pr_len;

	args_len = 0;
	va_start(args, text);
	ft_putendl("###############################");
	ft_putendl((char *)text);
	args_array = lex(text, args, &args_len);
	if (args_array != NULL)
	{
		pr = genstring(text, args_array, args_len);
		ft_putendl("__________________________________");
		ft_putendl(pr);
		pr_len = (int)ft_strlen(pr);
		if (pr != NULL)
			free(pr);
		if (args_array != NULL)
			free_args(args_len, args_array);
		va_end(args);
		return (pr_len);
	}
	va_end(args);
	return (0);
}
int main(void)
{
    // c_tests
    ft_printf("c Test 1: %c\n", '0');
    printf("c Test 1: %c\n", '0');
    ft_printf("c Test 2:  %c \n", '0');
    ft_printf("c Test 3:  %c\n", '0' - 256);
    ft_printf("c Test 4: %c \n", '0' + 256);
    ft_printf("c Test 5:  %c %c %c \n", '0', 0, '1');
    ft_printf("c Test 6:  %c %c %c \n", ' ', ' ', ' ');
    ft_printf("c Test 7:  %c %c %c \n", '1', '2', '3');
    ft_printf("c Test 8:  %c %c %c \n", '2', '1', 0);
    ft_printf("c Test 9:  %c %c %c \n", 0, '1', '2');

    // s_tests
    ft_printf("s Test 10: %s\n", "");
    ft_printf("s Test 11:  %s\n", "");
    ft_printf("s Test 12: %s \n", "");
    ft_printf("s Test 13:  %s \n", "");
    ft_printf("s Test 14:  %s \n", "-");
    ft_printf("s Test 15:  %s %s \n", "", "-");
    ft_printf("s Test 16:  %s %s \n", " - ", "");
    ft_printf("s Test 17:  %s %s %s %s %s\n", " - ", "", "4", "", "example");
    ft_printf("s Test 18:  %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
    ft_printf("s Test 19: NULL %s NULL \n", NULL);

    // p_tests
    ft_printf("p Test 20:  %p \n", (void *)-1);
    ft_printf("p Test 21:  %p \n", (void *)1);
    ft_printf("p Test 22:  %p \n", (void *)15);
    ft_printf("p Test 23:  %p \n", (void *)16);
    ft_printf("p Test 24:  %p \n", (void *)17);
    ft_printf("p Test 25:  %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
    ft_printf("p Test 26:  %p %p \n", (void *)INT_MIN, (void *)INT_MAX);
    ft_printf("p Test 27:  %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX); // Achtung, dies könnte undefiniertes Verhalten auslösen
    ft_printf("p Test 28:  %p %p \n", (void *)0, (void *)0);

    // Weitere Tests für d, i, u, x, X, und % könnten hier hinzugefügt werden, 
    // folgen aber dem gleichen Muster wie oben.

    // Beispiel für einen d_test
    ft_printf("d Test 29: %d\n", 0);
    // Füge hier weitere d_tests hinzu

    // Beispiel für einen i_test
    ft_printf("i Test 30: %i\n", -1);
    // Füge hier weitere i_tests hinzu

    // Beispiel für einen u_test
    ft_printf("u Test 31: %u\n", UINT_MAX);
    // Füge hier weitere u_tests hinzu

    // Beispiel für einen x_test
    ft_printf("x Test 32: %x\n", 0xabcdef);
    // Füge hier weitere x_tests hinzu

    // Beispiel für einen X_test
    ft_printf("X Test 33: %X\n", 0xABCDEF);
    // Füge hier weitere X_tests hinzu

    // Beispiel für einen %_test
    ft_printf("%% Test 34: %%\n");
    // Füge hier weitere %_tests hinzu

    // mix_tests
    ft_printf("Mix Test 35: %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);

    return 0;
}