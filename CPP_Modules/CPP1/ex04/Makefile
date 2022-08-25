# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 14:13:46 by cschwalm          #+#    #+#              #
#    Updated: 2022/07/16 11:32:47 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= c++ -Wall -Werror -Wextra -std=c++98
RM			= rm -f
NAME		= Loser

SRC			=	main.cpp \



all:		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(SRC) -g -o $(NAME)

clean:
			$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re