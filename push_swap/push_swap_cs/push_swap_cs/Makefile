# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 04:37:30 by cschwalm          #+#    #+#              #
#    Updated: 2022/02/27 05:57:09 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wextra -Wall -ggdb3 -I. 
CC = gcc
RM = rm -f

PUSH_SWAP_C = push_swap.c \
				libft/ft_putstr_fd.c \
				libft/ft_strlen.c \
				libft/ft_atoi.c \
				error/error.c \
				srcs/fill_stack_a.c \
				srcs/set_stacks.c \
				srcs/init_stacks.c \
				srcs/actions_sa_sb_ss.c \
				srcs/actions_ra_rb_rr.c \
				srcs/actions_pa_pb.c \
				srcs/actions_rra_rrb_rrr.c \
				srcs/sort_small.c \
				srcs/sort_medium.c \
				srcs/sort_medium_check.c \
				srcs/sort_medium_move.c \
				srcs/sort_medium_rotate.c \
				srcs/check_ascending.c \
				srcs/free_stacks.c

PUSH_SWAP_O = $(PUSH_SWAP_C:.c=.o)

all: push_swap

push_swap: $(PUSH_SWAP_O) push_swap.h
		$(CC) $(PUSH_SWAP_O) push_swap.h -o push_swap

clean:
	$(RM) $(PUSH_SWAP_O)

fclean: 
	$(RM) $(PUSH_SWAP_O) push_swap

re: fclean all