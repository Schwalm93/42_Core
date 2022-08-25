# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 10:50:29 by cschwalm          #+#    #+#              #
#    Updated: 2022/08/10 03:11:33 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC			= gcc
CFLAGS		= 
RM			= rm -f
NAME		= microshell

SRC			=	microshell.c \

OBJ			= $(SRC:c=o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re