# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschwalm <cschwalm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 04:37:30 by cschwalm          #+#    #+#              #
#    Updated: 2022/03/29 11:24:42 by cschwalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS =  -I. 
CC = gcc
RM = rm -f

PHILO_C =	philo.c \
				error/error_input.c \
				srcs/init_var.c \
				srcs/ft_atoi.c \
				srcs/timestemp.c \
				free/free_var.c

PHILO_O = $(PHILO_C:.c=.o)

all: philo

philo: $(PHILO_O) philo.h
		$(CC) $(PHILO_O) philo.h -lpthread -o philo

clean:
	$(RM) $(PHILO_O)

fclean: 
	$(RM) $(PHILO_O) philo

re: fclean all