NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra -ggdb3
LIB_LIB = Libft/libft.a
GNL_LIB = gnl/gnl.a
SRC = ./src/
EXE = ./executes/
EXE_UTILS = $(EXE)exe_utilitis/
SRC_UTILS = $(SRC)utilitis/
UNAME = $(shell uname)

ifeq ($(UNAME), Darwin)
	LDFLAGS			=	-L/usr/local/opt/readline/lib
	CPPFLAGS 		=	-I/usr/local/opt/readline/include
else
	LDFLAGS			=
	CPPFLAGS		=
endif

FILES = 	main.c \
			$(SRC)read.c \
			$(SRC)parse.c \
			$(SRC_UTILS)parse_utilities.c \
			$(SRC_UTILS)parse_utilities_2.c \
			$(SRC)redirect.c \
			$(SRC_UTILS)redirect_utilitis.c \
			$(SRC_UTILS)redirect_utilitis_2.c \
			$(SRC)sig.c \
			$(SRC)trim.c \
			$(SRC_UTILS)utilities.c\
			$(SRC_UTILS)utilities_2.c \
			$(SRC_UTILS)utilities_3.c \
			$(SRC)error.c \
			$(SRC)pipe.c \
			$(SRC)directing.c \
			$(EXE)echo.c \
			$(EXE)pwd.c \
			$(EXE)export.c \
			$(EXE_UTILS)echo_utilitis.c \
			$(EXE_UTILS)echo_utilitis_2.c \
			$(EXE)cd.c \
			$(EXE_UTILS)cd_supp_1.c \
			$(EXE_UTILS)cd_supp_1_helper.c \
			$(EXE_UTILS)cd_supp_2.c \
			$(EXE)env.c \
			$(EXE)unset.c \
			$(EXE)select_exe.c\
			$(EXE)exit.c \
			$(EXE)set.c \
			$(EXE)extern_execute.c \
			$(EXE_UTILS)extern_execute_utilitis.c \
			$(EXE_UTILS)extern_exe_supp.c \
			$(EXE_UTILS)export_utilitis.c \
			$(SRC_UTILS)ft_input_strncmp.c \
			$(EXE)status.c \
			$(SRC_UTILS)ft_putstr_fd_custom.c \



OBJS =		$(FILES:.c=.o)

%.o: %.c
			$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			make bonus -C Libft
			make -C gnl
			$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(CPPFLAGS) $(LIB_LIB) $(GNL_LIB) -lreadline -o $@

clean:
			make clean -C Libft
			make clean -C gnl
			rm -f $(OBJS)

fclean:	clean
			make fclean -C Libft
			make fclean -C gnl
			rm -f $(NAME)

re:		fclean all
