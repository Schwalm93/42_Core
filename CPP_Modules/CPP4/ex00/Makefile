# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 07:35:52 by cschwalm          #+#    #+#              #
#    Updated: 2022/09/23 08:55:35 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= c++ -Wall -Werror -Wextra -std=c++98
RM			= rm -f
NAME		= run

SRC			=	main.cpp \
				Animal.cpp \
				Cat.cpp \
				Dog.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \


all:		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(SRC) -g -o $(NAME)

clean:
			$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re