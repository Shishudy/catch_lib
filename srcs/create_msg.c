/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:41:04 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/08 16:43:08 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch.h"

int	check_format(char *str)
{
	if (str[0] == '%' && str[1] != '\0' && (str[1] == '%' || str[1] == 'c' || \
str[1] == 's' || str[1] == 'd' || str[1] == 'u' || str[1] == 'x' || \
str[1] == 'X' || str[1] == 'p'))
		return (1);
	return (0);
}

void	str_concat(char *str1, char *str2)
{
	int	i;
	int	str1len;

	str1len = 0;
	if (str1[0] != '\0')
		str1len = ft_strlen(str1);
	i = 0;
	while (str2[i] != '\0')
	{
		str1[str1len + i] = str2[i];
		i++;
	}
}

void	alloc_error_msg(char *str, t_error_var *error_vars, char **error_msg)
{
	int			i;
	int			len;
	int			var;
	t_error_var	dummy;

	i = 0;
	len = 0;
	var = 0;
	while (str[i] != '\0')
	{
		if (check_format(&str[i]))
		{
			i++;
			len = len + ft_strlen(((t_error_var *)get_node_at_index(error_vars, \
get_offset(&dummy, &dummy.next), var++))->converted_var) - 1;
		}
		len++;
		i++;
	}
	*error_msg = ft_calloc(len + 1, sizeof(char));
}

void	build_error_msg(char *str, t_error_var *error_vars, char *error_msg)
{
	int			var;
	int			i_str;
	int			i_estr;
	t_error_var	dummy;

	var = 0;
	i_str = 0;
	i_estr = 0;
	while (str[i_str] != '\0')
	{
		if (check_format(&str[i_str]))
		{
			i_str++;
			str_concat(error_msg, ((t_error_var *)get_node_at_index(error_vars, \
get_offset(&dummy, &dummy.next), var))->converted_var);
			i_estr += ft_strlen(((t_error_var *)get_node_at_index(error_vars, \
get_offset(&dummy, &dummy.next), var++))->converted_var);
		}
		else
		{
			error_msg[i_estr] = str[i_str];
			i_estr++;
		}
		i_str++;
	}
}
