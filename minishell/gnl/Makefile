NAME = gnl.a

CFLAGS = -Wall -Wextra -Werror -I. -ggdb3
CC				= gcc
RM				= rm -f

FILES =		get_next_line_bonus.c \
			get_next_line_utils_bonus.c \


OBJS			= $(FILES:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
