# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 02:08:30 by cschwalm          #+#    #+#              #
#    Updated: 2022/09/30 01:25:10 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= c++ -Wall -Werror -Wextra -std=c++98
RM			= rm -f
NAME		= run

SRC			=	main.cpp \
				Bureaucrat.hpp \
				Bureaucrat.cpp \
				Form.cpp \


all:		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(SRC) -g -o $(NAME)

clean:
			$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re