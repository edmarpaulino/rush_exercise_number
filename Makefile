# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 12:01:33 by edpaulin          #+#    #+#              #
#    Updated: 2022/02/05 12:13:45 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush_exercise_number

SRC = rush_exercise_number.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean: clean

re: fclean all

.PHONY: all clean fclean re