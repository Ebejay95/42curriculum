/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:08:34 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 17:02:22 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

#define INT_UNSET_VALUE -1
#define UINT_UNSET_VALUE 4294967295U

typedef enum e_type
{
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
}					t_type;

typedef struct s_flex_type
{
	int				c;
	char			*s;
	void			*p;
	int				d;
	int				i;
	unsigned int	u;
	unsigned int	x;
	unsigned int	xup;
	char			*percent;
	int				invalid;
}					t_flex_type;

typedef struct s_pf_arg
{
	t_type			type;
	t_flex_type		value;
	char			*printable;
	char			*needle;
}					t_pf_arg;

int					ft_printf(const char *text, ...);
t_pf_arg			**lex(const char *text, va_list args, size_t *args_len);
t_pf_arg			*create_arg(const char typechr, va_list args);
void				*free_args(size_t idx, t_pf_arg **args);
char				*get_pr_by_val(t_flex_type *value);
char				*genstring(const char *text, t_pf_arg **args_array,
						size_t args_len);