# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbartkow <jbartkow@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 16:54:34 by jbartkow          #+#    #+#              #
#    Updated: 2022/06/29 16:54:49 by jbartkow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS	= -Wall -Werror -Wextra -ggdb3
LIBFT	= ./library/Libft
GNL		= ./library/gnl
LIB_LIB	= $(LIBFT)/libft.a
GNL_LIB	= $(GNL)/gnl.a
SRC		= ./src/
MAP		= ./map/
RAY		= $(SRC)raycasting/
IN		= $(SRC)input_check/
MOVE	= $(SRC)move/
UTIL	= $(SRC)utilitis/
UNAME = $(shell uname)

ifeq ($(UNAME), Darwin)
	MLX	= ./mlx
	MLX_LIB	= mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit
else
	MLX	= ./mlx_linux
	MLX_LIB	= mlx_linux/libmlx_Linux.a -Imlx_linux -lXext -lX11 -lm -lz
endif

FILES = 	main.c \
			$(IN)check_input_argv.c \
			$(IN)init_struct.c \
			$(IN)check_pictures.c \
			$(IN)init_player.c \
			$(UTIL)ft_exit.c \
			$(UTIL)ft_free.c \
			$(UTIL)ft_trim.c \
			$(UTIL)ft_destroy.c \
			$(MAP)map.c \
			$(MAP)map_utils.c \
			$(MAP)map_utils2.c \
			$(MAP)map_helper1.c \
			$(MAP)map_helper2.c \
			$(MAP)check_map.c \
			$(MOVE)keyhooks.c \
			$(MOVE)vision.c \
			$(MOVE)wall_collision.c \
			$(MOVE)movement.c \
			$(MOVE)keyhooks_helper.c \
			$(MOVE)keyhooks_helper_2.c \
			$(RAY)raycasting.c \
			$(RAY)calc.c \
			$(RAY)draw.c \
			$(RAY)draw_helper.c \

OBJS =		$(FILES:.c=.o)

BOFILES = 	main_bonus.c \
			$(IN)check_input_argv_bonus.c \
			$(IN)init_struct_bonus.c \
			$(IN)check_pictures_bonus.c \
			$(IN)init_player_bonus.c \
			$(UTIL)ft_exit_bonus.c \
			$(UTIL)ft_free_bonus.c \
			$(UTIL)ft_trim_bonus.c \
			$(UTIL)ft_destroy_bonus.c \
			$(MAP)map_bonus.c \
			$(MAP)map_utils_bonus.c \
			$(MAP)map_utils2_bonus.c \
			$(MAP)map_helper1_bonus.c \
			$(MAP)map_helper2_bonus.c \
			$(MAP)check_map_bonus.c \
			$(MOVE)keyhooks_bonus.c \
			$(MOVE)vision_bonus.c \
			$(MOVE)wall_collision_bonus.c \
			$(MOVE)movement_bonus.c \
			$(MOVE)keyhooks_helper_bonus.c \
			$(MOVE)keyhooks_helper_2_bonus.c \
			$(RAY)raycasting_bonus.c \
			$(RAY)calc_bonus.c \
			$(RAY)minimap_bonus.c \
			$(RAY)draw_bonus.c \
			$(RAY)draw_helper_bonus.c \

BOOBJS =		$(BOFILES:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(MLX)
			make bonus -C $(LIBFT)
			make -C $(GNL)
			$(CC) $(CFLAGS) $(OBJS) $(LIB_LIB) $(GNL_LIB) $(MLX_LIB) -o $@

clean:
			make clean -C $(LIBFT)
			make clean -C $(GNL)
			make clean -C $(MLX)
			rm -f $(OBJS)
			rm -f $(BOOBJS)

fclean:	clean
			make fclean -C $(LIBFT)
			make fclean -C $(GNL)
			make clean -C $(MLX)
			rm -rf mlx/libmlx.a
			rm -f $(NAME)
			rm -f cub3D_bonus

re:		fclean all

bonus:		$(BOOBJS)
			make -C $(MLX)
			make bonus -C $(LIBFT)
			make -C $(GNL)
			$(CC) $(CFLAGS) $(BOOBJS) $(LIB_LIB) $(GNL_LIB) $(MLX_LIB) -o cub3D_bonus

