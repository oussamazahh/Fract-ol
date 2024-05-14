# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 16:16:54 by ozahidi           #+#    #+#              #
#    Updated: 2024/05/14 17:10:53 by ozahidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -lmlx -framework OpenGL -framework AppKit
#  -g  -fsanitize=address
NAME = fractol

BNAME = fractol_bonus

SRCS = $(addprefix mandatory/,ft_fractol.c mouse_hook.c \
			julia_set.c keys_hook.c extra_func.c draw_tools.c \
			calcule_complex.c calcul_tools.c drawing_sciling.c checking_inputs.c)

BSRCS = $(addprefix bonus/,extra_func_bonus.c keys_hooks_bonus.c \
			julia_set_bonus.c mouse_hook_bonus.c \
			draw_tools_bonus.c calcule_tools_bonus.c checking_inputs_bonus.c \
			ft_fractol_bonus.c drawing_sciling_bonus.c calcule_complex_bonus.c)

OBJS = ${SRCS:.c=.o}

BOBJS = ${BSRCS:.c=.o}

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

%.o: %.c mandatory/ft_fractal.h bonus/ft_fractal_bonus.h
	@${CC} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS} 
	@echo  "${RED}[Building fractol]${NC}"
	@${CC} ${OBJS} ${CFLAGS} -o ${NAME}
	@echo  "${GREEN} >>DONE<<${NC}" 

bonus : ${BOBJS} 
	@echo  "${RED}[Building fractol_bonus]${NC}"
	@${CC} ${BOBJS} ${CFLAGS} -o ${BNAME}
	@echo  "${GREEN} >>DONE<<${NC}" 

clean:
	@echo  "${RED}[Deleting objects]${NC}"
	@rm -rf ${OBJS}
	@rm -rf ${BOBJS}
	@echo  "${GREEN} >>DONE<<${NC}" 

fclean: clean
	@echo  "${RED}[Deleting Program]${NC}"
	@rm -rf ${NAME}
	@rm -rf ${BNAME}
	@echo  "${GREEN} >>DONE<<${NC}" 

re: fclean all

.PHONY : all clean fclean re