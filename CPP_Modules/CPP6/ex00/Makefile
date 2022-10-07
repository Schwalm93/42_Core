# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 04:48:12 by cschwalm          #+#    #+#              #
#    Updated: 2022/10/02 03:42:38 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	convert
CC				=	c++
CFLAG			=	-Wall -Wextra -Werror -std=c++98

FILE			=	main.cpp \
					Converter.cpp 


OBJS =		$(FILE:.cpp=.o)

%.o: %.cpp
			$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAG) $(OBJS) -ggdb3 -o $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re