# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguth <tguth@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 06:52:54 by kali              #+#    #+#              #
#    Updated: 2022/02/07 07:37:37 by tguth            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
NAME= so_long
RM= rm -f

SRC=	ft_so_long.c \
		./source/get_next_line/get_next_line.c \
		./source/get_next_line/get_next_line_utils.c \
		./source/ft_utilitis.c \
		./source/ft_check_input.c \
		./source/ft_check_input_2.c \
		./source/ft_so_long_utilitis.c \
		./move/ft_player_move.c\
		./move/ft_player_move_utilitis.c \
		./move/ft_player_move_utilitis_2.c \
		./map/ft_map_init.c\
		./map/ft_map_init_utilitis.c \
		./map/ft_map_init_utilitis_2.c \

OBJ =			$(SRC:.c=.o)

MLX= mlx/libmlx_Linux.a
LIBFT = source/Libft/libft.a


all: $(NAME)

$(NAME):	$(OBJ)
			make -C ./mlx
			make bonus -C ./source/Libft
			$(CC) $(OBJ) $(MLX) $(LIBFT) -lXext -lX11 -lm -lz -o $(NAME)

clean:		clean
			$(RM) $(OBJ)
			make clean -C ./source/Libft

fclean:
			$(RM) so_long
			make fclean -C ./source/Libft
