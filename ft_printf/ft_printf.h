/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathaneberle <jonathaneberle@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:08:34 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/22 16:50:24 by jonathanebe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *text, ...);
char	*ft_itoa(int n);
int		ft_putstr(char *s);
char	*ft_strbase(unsigned long long input, const char *base);
size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putunbrr(unsigned int n);
int		ft_putnbrr(int n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *start, int fill, size_t size);
size_t	ft_strlcpy(char *trg, const char *src, size_t size);
int		ft_str_is_unique(char *str);
int		ft_isprint(int c);
int		smart_print_c(int c);
int		smart_print_s(char *s);
int		smart_print_p(void *p);
int		smart_print_d(int i);
int		smart_print_i(int i);
int		smart_print_u(unsigned int i);
int		smart_print_x(unsigned int i);
int		smart_print_xup(unsigned int i);
int		smart_print(char type, va_list args);
int		null_pointer(void);
#endif