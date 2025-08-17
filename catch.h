/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:41:16 by rafasant          #+#    #+#             */
/*   Updated: 2025/08/11 14:40:30 by rafasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATCH_H
# define CATCH_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_catch
{
	bool		alloc_mem;
	char		*error_msg;
	void		(*set)(char *s, ...);
	void		(*print)();
	void		(*free)();
}				t_catch;

typedef struct s_error_var
{
	char				*converted_var;
	struct s_error_var	*next;
}				t_error_var;

/*------------- catch.c -------------*/
t_catch		*catch(void);

/*------------- create_msg.c -------------*/
int			check_format(char *str);
void		alloc_error_msg(char *str, t_error_var *error_vars, \
char **error_msg);
void		build_error_msg(char *str, t_error_var *error_vars, \
char *error_msg);

/*------------- converter.c -------------*/
char		*converter(char c, va_list args);
t_error_var	*create_var(char c, va_list args);
t_error_var	*convert_vars(char *str, va_list args);

/*------------- converter_functions.c -------------*/
char		*allocate_char(char c);
char		*allocate_string(char *s);
char		*allocate_long(long int n, char *base_to);
char		*allocate_pointer(unsigned long int n, char *base_to);

/*------------- utils.c -------------*/
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *str);
size_t		ft_strlen(const char *str);
void		str_concat(char *str1, char *str2);
void		free_vars(t_error_var *error_vars);

/*------------- list_functions.c -------------*/
size_t		get_offset(void *struct_ptr, void *member_ptr);
void		*get_last_node(void *node, size_t next_offset);
void		*get_node_at_index(void *node, size_t next_offset, int index);
int			get_list_size(void *node, size_t next_offset);

#endif