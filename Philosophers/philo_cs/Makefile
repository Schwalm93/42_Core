# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 04:37:30 by cschwalm          #+#    #+#              #
#    Updated: 2022/04/20 10:09:46 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS =  -I. 
CC = gcc
RM = rm -f

PHILO_C =	philo.c \
				error/error_input.c \
				error/error_init.c \
				srcs/init.c \
				srcs/ft_atoi.c \
				srcs/timenow.c \
				srcs/actions.c \
				free/free_var.c

PHILO_O = $(PHILO_C:.c=.o)

all: philo

philo: $(PHILO_O) philo.h
		$(CC) $(PHILO_O) -lpthread -o philo

clean:
	$(RM) $(PHILO_O)

fclean: 
	$(RM) $(PHILO_O) philo

re: fclean all

.PHONY: all clean fclean re