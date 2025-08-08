/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:23:54 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/08 16:43:12 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch.h"

size_t	get_offset(void *struct_ptr, void *member_ptr)
{
	return ((size_t)((char *)member_ptr - (char *)struct_ptr));
}

void	*get_last_node(void *node, size_t next_offset)
{
	char	*tmp;

	tmp = (char *)node;
	if (!tmp)
		return (NULL);
	while (*(void **)(tmp + next_offset))
		tmp = *(char **)(tmp + next_offset);
	return ((void *)tmp);
}

void	*get_node_at_index(void *node, size_t next_offset, int index)
{
	int		i;
	char	*tmp;

	tmp = (char *)node;
	if (!tmp)
		return (NULL);
	i = 0;
	while (i != index && *(void **)(tmp + next_offset))
	{
		tmp = *(char **)(tmp + next_offset);
		i++;
	}
	return ((void *)tmp);
}

int	get_list_size(void *node, size_t next_offset)
{
	int		size;
	char	*tmp;

	tmp = (char *)node;
	if (!tmp)
		return (0);
	size = 0;
	while (tmp)
	{
		tmp = *(char **)(tmp + next_offset);
		size++;
	}
	return (size);
}
