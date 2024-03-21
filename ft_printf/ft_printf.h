/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:08:34 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/21 16:31:20 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *text, ...);
char	*ft_itoa(int n);
void	ft_putstr(char *s);
char	*ft_strbase(unsigned long long input, const char *base);
size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
int		ft_putunbrr(unsigned int n);
int		ft_putnbrr(int n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *start, int fill, size_t size);
size_t	ft_strlcpy(char *trg, const char *src, size_t size);
int		ft_str_is_unique(char *str);

#endif