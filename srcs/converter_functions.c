/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:41:02 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/08 16:43:00 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch.h"

char	*allocate_char(char c)
{
	char	*var;

	var = ft_calloc(2, sizeof(char));
	if (!var)
		return (NULL);
	var[0] = c;
	var[1] = '\0';
	return (var);
}

char	*allocate_string(char *s)
{
	char	*var;

	if (!s)
		var = ft_strdup("NULL");
	else
		var = ft_strdup(s);
	if (!var)
		return (NULL);
	return (var);
}

int	ft_len(long int n, int base_len)
{
	int	len;
	int	temp;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	temp = n;
	while (temp)
	{
		temp = temp / base_len;
		len++;
	}
	return (len);
}

char	*allocate_long(long int n, char *base_to)
{
	int		base_len;
	int		len;
	char	*nstr;

	base_len = ft_strlen(base_to);
	len = ft_len(n, base_len);
	nstr = ft_calloc(len + 1, sizeof(char));
	if (!nstr)
		return (NULL);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		nstr[--len] = base_to[n % base_len];
		n = n / base_len;
	}
	if (len != 0)
		nstr[--len] = '-';
	return (nstr);
}

char	*allocate_pointer(unsigned long int n, char *base_to)
{
	unsigned long int	temp;
	int					len;
	int					base_len;
	char				*nstr;

	len = 0;
	base_len = ft_strlen(base_to);
	temp = n;
	while (temp)
	{
		temp = temp / base_len;
		len++;
	}
	nstr = ft_calloc(len + 3, sizeof(char));
	if (!nstr)
		return (NULL);
	nstr[0] = '0';
	nstr[1] = 'x';
	while (n)
	{
		nstr[len + 1] = base_to[n % base_len];
		n = n / base_len;
		len--;
	}
	return (nstr);
}
