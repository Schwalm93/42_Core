# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 07:35:52 by cschwalm          #+#    #+#              #
#    Updated: 2022/09/25 09:48:13 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= c++ -Wall -Werror -Wextra -std=c++98
RM			= rm -f
NAME		= run

SRC			=	main.cpp \
				AAnimal.cpp \
				Cat.cpp \
				Dog.cpp \
				Brain.cpp \


all:		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(SRC) -g -o $(NAME)

clean:
			$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re