# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 15:19:22 by cschwalm          #+#    #+#              #
#    Updated: 2022/01/26 05:33:52 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I.
CC				= gcc
RM				= rm -f

SERVER_C =	server.c \
			srcs/ft_putstr_fd.c \
			srcs/ft_putnbr_fd.c \
			srcs/ft_strlen.c

SERVER_OBJS			= $(SERVER_C:.c=.o)

CLIENT_C =	client.c \
			srcs/ft_atoi.c \
			srcs/ft_putstr_fd.c \
			srcs/ft_strlen.c

CLIENT_OBJS			= $(CLIENT_C:.c=.o)

all: server client

bonus: bonus_c bonus_s

server:	$(SERVER_OBJS)
		$(CC) $(SERVER_OBJS) minitalk.h -o server

client:	$(CLIENT_OBJS)
		$(CC) $(CLIENT_OBJS) minitalk.h -o client

bonus_s:	$(SERVER_OBJS)
		$(CC) $(SERVER_OBJS) minitalk.h -o server_bonus

bonus_c:	$(CLIENT_OBJS)
		$(CC) $(CLIENT_OBJS) minitalk.h -o client_bonus

clean:
		$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
		$(RM) server client server_bonus client_bonus

re: fclean all