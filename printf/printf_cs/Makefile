# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 04:08:47 by cschwalm          #+#    #+#              #
#    Updated: 2022/01/11 10:01:45 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I.
CC				= gcc
RM				= rm -f

FILES =		ft_printf.c \
			srcs/ft_print_percent.c \
			srcs/ft_print_pointer.c \
			srcs/ft_print_pointer_l.c \
			srcs/ft_print_pointer_u.c \
			srcs/ft_putchar.c \
			srcs/ft_putnbr.c \
			srcs/ft_uputnbr.c \
			srcs/ft_putstr.c \
			srcs/ft_strlen.c \


OBJS			= $(FILES:.c=.o)


all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus