# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 13:46:09 by cschwalm          #+#    #+#              #
#    Updated: 2022/02/09 11:44:19 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

CC		= gcc  -Wextra -Werror -Wall -ggdb3
MLX		= mlx_linux/libmlx_Linux.a
RM		= rm -f 

SRC=	so_long.c \
		hooks/hooks.c \
		hooks/move.c \
		img/img_init.c \
		map/read_map.c \
		map/map_init.c \
		map/check_map.c \
		map/check_map2.c \
		map/check_map3.c \
		srcs/ft_exit.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_putnbr_fd.c \
		error/ft_error_handling.c
		

GNL=	gnl/get_next_line.c \
		gnl/get_next_line_utils.c


all: $(NAME)

$(NAME):	$(SRC)
		make -C ./mlx_linux
		$(CC) $(SRC) $(MLX) $(GNL) -lXext -lX11 -lm -lz -o $(NAME)

clean:		clean
		$(RM) $(NAME)

fclean:		clean
		$(RM) $(NAME)

re: fclean all

