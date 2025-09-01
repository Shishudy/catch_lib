# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 18:41:12 by rafasant          #+#    #+#              #
#    Updated: 2025/09/01 19:46:56 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror ${HEADERS}
NAME 		= catch.a
AR			= ar -rcs
RM 			= rm -rf
HEADERS 	= $(addprefix -I, .)
SRCS 		= $(addprefix ${SRCS_DIR}, catch.c create_msg.c converter.c \
				converter_functions.c utils.c list_functions.c)
OBJS		= ${SRCS:${SRCS_DIR}%.c=${OBJS_DIR}%.o}
SRCS_DIR	= srcs/
OBJS_DIR	= objs/

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@mkdir -p objs
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}
${NAME} : ${OBJS}
	@${AR} ${NAME} ${OBJS}
	@if [ "$(MAKELEVEL)" -eq 0 ]; then echo "Compiled ${NAME}!"; fi

clean: 
	@${RM} ${OBJS_DIR}
	@if [ "$(MAKELEVEL)" -eq 0 ]; then echo "Cleaned object files!"; fi

fclean: clean
	@${RM} ${NAME}
	@if [ "$(MAKELEVEL)" -eq 0 ]; then echo "Cleaned executables!"; fi

re: fclean all

.PHONY: clean, fclean, all, re