/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:14:10 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 10:20:11 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

e_type	get_e_by_chr(const char typechr)
{
	if (typechr == 'c')
		return (CHAR);
	if (typechr == 's')
		return (STRING);
	if (typechr == 'p')
		return (VOID);
	if (typechr == 'd')
		return (DECIM);
	if (typechr == 'i')
		return (INT);
	if (typechr == 'u')
		return (UINT);
	if (typechr == 'x')
		return (HEXA_LW);
	if (typechr == 'X')
		return (HEXA_UP);
	if (typechr == '%')
		return (PERCENT);
	return (INVALID);
}

void	*free_args(size_t idx, t_pf_arg **args)
{
	while (idx >= 0)
	{
		free(args[idx]);
		idx--;
	}
	free(args);
	return (NULL);
}

t_flex_type *set_val_defaults(t_flex_type *value)
{
	value->c = INT_UNSET_VALUE;
	value->s = NULL;
	value->p = NULL;
	value->d = INT_UNSET_VALUE;
	value->i = INT_UNSET_VALUE;
	value->u = UINT_UNSET_VALUE;
	value->x = UINT_UNSET_VALUE;
	value->X = UINT_UNSET_VALUE;
	value->percent = INT_UNSET_VALUE;
	return (value);
}

void	*get_val_by_va_arg(e_type type, va_list args)
{
	t_flex_type *value;
	value = ft_calloc(1, sizeof(t_flex_type));
	if(value != NULL)
		value = set_val_defaults(value);
	if (type == CHAR && value != NULL)
		value->c = va_arg(args, int);
	else if(type == STRING && value != NULL)
		value->s = va_arg(args, char *);
	else if(type == VOID && value != NULL)
		value->p = va_arg(args, void *);
	else if(type == DECIM && value != NULL)
		value->d = va_arg(args, int);
	else if(type == INT && value != NULL)
		value->i = va_arg(args, int);
	else if(type == UINT && value != NULL)
		value->u = va_arg(args, unsigned int);
	else if(type == HEXA_LW && value != NULL)
		value->x = va_arg(args, unsigned int);
	else if(type == HEXA_UP && value != NULL)
		value->X = va_arg(args, unsigned int);
	else if(type == PERCENT && value != NULL)
		value->percent = va_arg(args, int);
	else if(type == INVALID && value != NULL)
		free(value);
	return (value);
}


t_pf_arg	*create_arg(const char typechr, va_list args)
{
	t_pf_arg		*new;
	e_type			type;
	t_flex_type		*value;
	char			*printable;
	char			*needle;

	needle = ft_calloc(2, sizeof(char));
	if(needle)
		*needle = typechr;
	type = get_e_by_chr(typechr);
	value = get_val_by_va_arg(type, args);
	new = ft_calloc(1, sizeof(t_pf_arg));
	printable = get_pr_by_val(value);
	new->type = type;
	new->value = *value;
	new->printable = printable;
	new->needle = ft_strjoin("%", needle);
	return (new);
}
