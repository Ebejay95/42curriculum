/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:00:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 10:23:00 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_pr_by_val(t_flex_type *value)
{
	if	(value->c != INT_UNSET_VALUE)
		return ft_itoa(value->c);
	else if	(value->s != NULL)
		return value->s;
	else if	(value->p != NULL)
		return ft_strjoin("0x", ft_strbase((int) value->p, "0123456789ABCDEF"));
	else if	(value->d != INT_UNSET_VALUE)
		return ft_itoa(value->d);
	else if	(value->i != INT_UNSET_VALUE)
		return ft_itoa(value->i);
	else if	(value->u != UINT_UNSET_VALUE)
		return ft_itoa(value->u);
	else if	(value->x != UINT_UNSET_VALUE)
		return ft_strbase(value->x, "0123456789abcdef");
	else if	(value->X != UINT_UNSET_VALUE)
		return ft_strbase(value->X, "0123456789ABCDEF");
	else if	(value->percent != INT_UNSET_VALUE)
		return "%";
	return (NULL);
}

char	*genstring(const char *text, t_pf_arg **args_array, size_t args_len)
{
	char	*result;
	size_t	i;

	i = 0;
	result = ft_strdup(text);
	if(!result)
		return (NULL);
	while (i < args_len)
	{
		if(args_array[i]->printable != NULL)
			ft_putendl(args_array[i]->needle);
			ft_putendl(args_array[i]->printable);
			result = ft_strreplace(result, args_array[i]->needle, args_array[i]->printable);
		i++;
	}
	return (result);
}