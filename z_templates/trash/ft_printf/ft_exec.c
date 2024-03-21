/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:00:05 by jeberle           #+#    #+#             */
/*   Updated: 2024/03/20 17:53:41 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_pr_by_val(t_flex_type *value)
{
	char	*tmp;

	if (value->c != INT_UNSET_VALUE)
	{
		tmp = ft_itoa(value->c);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	else if (value->s != NULL)
	{
		tmp = ft_strdup(value->s);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	else if (value->s == NULL)
	{
	    tmp = ft_strdup("(null)");
	    if (!tmp)
	        return (NULL);
	    return (tmp);
	}
	else if (value->p != NULL)
	{
		tmp = ft_strjoin("0x", ft_strbase((int)value->p, "0123456789ABCDEF"));
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	else if (value->d != INT_UNSET_VALUE)
	{
		tmp = ft_itoa(value->d);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	else if (value->i != INT_UNSET_VALUE)
	{
		tmp = ft_itoa(value->i);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	else if (value->u != UINT_UNSET_VALUE)
	{
		tmp = ft_itoa(value->u);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	else if (value->x != UINT_UNSET_VALUE)
	{
		tmp = ft_strbase(value->x, "0123456789abcdef");
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	else if (value->xup != UINT_UNSET_VALUE)
	{
		tmp = ft_strbase(value->xup, "0123456789ABCDEF");
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	else if (value->percent != NULL)
	{
		tmp = ft_strdup(value->percent);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	return (NULL);
}

char	*genstring(const char *text, t_pf_arg **args_array, size_t args_len)
{
	char	*result;
	char	*tmp;
	size_t	i;

	i = 0;
	result = ft_strdup(text);
	if (!result)
		return (NULL);
	while (i < args_len)
	{
		if (args_array[i]->printable != NULL)
			tmp = ft_strreplace(result, args_array[i]->needle,
					args_array[i]->printable);
		if (tmp != NULL)
		{
			free(result);
			result = tmp;
		}
		else
		{
			free(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}
