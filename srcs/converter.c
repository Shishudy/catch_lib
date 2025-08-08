/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:40:59 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/08 16:43:04 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch.h"

char	*converter(char c, va_list args)
{
	unsigned long	i;

	if (c == '%')
		return (allocate_char('%'));
	else if (c == 'c')
		return (allocate_char(va_arg(args, int)));
	else if (c == 's')
		return (allocate_string(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (allocate_long(va_arg(args, int), "0123456789"));
	else if (c == 'u')
		return (allocate_long(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (allocate_long(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (allocate_long(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
	{
		i = va_arg(args, unsigned long int);
		if (i == 0)
			return (ft_strdup("(nil)"));
		else
			return (allocate_pointer(i, "0123456789abcdef"));
	}
	return (NULL);
}

t_error_var	*create_var(char c, va_list args)
{
	t_error_var	*new_error;

	new_error = ft_calloc(1, sizeof(t_error_var));
	if (!new_error)
		return (NULL);
	new_error->next = NULL;
	new_error->converted_var = converter(c, args);
	if (new_error->converted_var == NULL)
		return (free(new_error), NULL);
	return (new_error);
}

t_error_var	*convert_vars(char *str, va_list args)
{
	int			i;
	t_error_var	dummy;
	t_error_var	*new_error;
	t_error_var	*error_vars;

	i = 0;
	error_vars = NULL;
	while (str[i] != '\0')
	{
		if (check_format(&str[i]))
		{
			i++;
			new_error = create_var(str[i], args);
			if (new_error == NULL)
				return (free(error_vars), NULL);
			if (error_vars != NULL)
				((t_error_var *)get_last_node(error_vars,\
					get_offset(&dummy, &dummy.next)))->next = new_error;
			else
				error_vars = new_error;
		}
		i++;
	}
	if (error_vars == NULL)
		error_vars = ft_calloc(1, sizeof(t_error_var));
	return (error_vars);
}
