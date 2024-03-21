/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:08:34 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 18:38:14 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

#define INT_UNSET_VALUE -1
#define UINT_UNSET_VALUE 4294967295U



int					ft_printf(const char *text, ...);