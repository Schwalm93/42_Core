# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 14:13:46 by cschwalm          #+#    #+#              #
#    Updated: 2022/07/09 03:02:57 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++98
RM			= rm -f
NAME		= megaphone

SRC			= megaphone.cpp

OBJ			= $(SRC:cpp=o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re