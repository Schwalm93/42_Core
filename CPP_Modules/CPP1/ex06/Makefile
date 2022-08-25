# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 14:13:46 by cschwalm          #+#    #+#              #
#    Updated: 2022/08/25 04:07:22 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= c++ -Wall -Werror -Wextra -std=c++98
RM			= rm -f
NAME		= harlFilter

SRC			=	main.cpp \
				Harl.cpp


all:		$(NAME)

$(NAME):	$(SRC)
			$(CC) $(SRC) -g -o $(NAME)

clean:
			$(RM) $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re