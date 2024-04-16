# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 16:16:54 by ozahidi           #+#    #+#              #
#    Updated: 2024/04/15 18:35:55 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -lmlx -framework OpenGL -framework AppKit  

NAME = fractal

BNAME = fractal_bonus

SRCS = mandatory/ft_fractla.c mandatory/utils.c mandatory/utils1.c \
	mandatory/hooks.c mandatory/calcul_tools.c mandatory/calcul_complex.c

BSRCS = bonus/ft_fractla_bonus.c  bonus/hooks_bonus.c  bonus/draw_tools_bonus.c \
	bonus/utils_bonus.c bonus/utils1_bonus.c bonus/utils2_bonus.c bonus/calcule_tools_bonus.c

OBJS = ${SRCS:.c=.o}

BOBJS = ${SRCS:.c=.o}

%.o: %.c mandatory/ft_fractal.h bonus/ft_fractal_bonus.h
	${CC} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS} 
	${CC} ${SRCS} ${CFLAGS} -o ${NAME}

bonus : ${BOBJS} 
	${CC} ${BSRCS} ${CFLAGS} -o ${BNAME}

clean:
	rm -rf ${OBJS}
	rm -rf ${BOBJS}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${BNAME}

re: fclean all

.PHONY : all clean fclean re