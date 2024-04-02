# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 16:16:54 by ozahidi           #+#    #+#              #
#    Updated: 2024/04/02 17:54:18 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fractal

SRCS = ft_fractal.c utils.c

OBJS = ${SRCS:.c=.o}

%.o: %.c ft_fractal.h
	${CC} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${SRCS} ${CFLAGS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY : all clean fclean re