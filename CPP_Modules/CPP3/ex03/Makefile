# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 13:03:12 by cschwalm          #+#    #+#              #
#    Updated: 2022/09/08 05:40:36 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC			= c++ -Wall -Werror -Wextra -std=c++98
RM			= rm -f
NAME		= run

SRC			=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \



all:		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(SRC) -g -o $(NAME)

clean:
			$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re