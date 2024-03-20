/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:08:34 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 10:19:29 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

//%c Prints a single character.
//%s Prints a string (as defined by the common C convention).
//%p The void * pointer argument has to be printed in hexadecimal format.
//%d Prints a decimal (base 10) number.
//%i Prints an integer in base 10.
//%u Prints an unsigned decimal (base 10) number.
//%x Prints a number in hexadecimal (base 16) lowercase format.
//%X Prints a number in hexadecimal (base 16) uppercase format.
//%% Prints a percent sign.
typedef enum {
	CHAR,
	STRING,
	VOID,
	DECIM,
	INT,
	UINT,
	HEXA_LW,
	HEXA_UP,
	PERCENT,
	INVALID
} e_type;
#define INT_UNSET_VALUE -1
#define UINT_UNSET_VALUE 4294967295U

typedef struct s_flex_type
{
	int				c;
	char			*s;
	void			*p;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	X;
	int				percent;
	int				invalid;
} t_flex_type;

typedef struct s_pf_arg
{
	e_type		type;
	t_flex_type	value;
	char		*printable;
	char		*needle;
} t_pf_arg;

void		ft_printf(const char *text, ...);
t_pf_arg	**lex(const char *text, va_list args, size_t *args_len);
t_pf_arg	*create_arg(const char typechr, va_list args);
void		*free_args(size_t idx, t_pf_arg **args);
char		*get_pr_by_val(t_flex_type *value);
char	*genstring(const char *text, t_pf_arg **args_array, size_t args_len);