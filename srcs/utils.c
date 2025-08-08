/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:41:06 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/08 16:43:16 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len != 0)
	{
		*p = c;
		len--;
		p++;
	}
	return (b);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	value;

	value = nmemb * size;
	if (value && (value / size) != nmemb)
		return (NULL);
	array = malloc(value);
	if (!array)
		return (NULL);
	ft_memset(array, 0, value);
	return (array);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	free_vars(t_error_var *error_vars)
{
	t_error_var	*temp;

	while (error_vars != NULL)
	{
		temp = error_vars->next;
		if (error_vars->converted_var)
			free(error_vars->converted_var);
		free(error_vars);
		error_vars = temp;
	}
}
