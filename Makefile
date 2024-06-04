NAME			:=	shell
SRCS			:=	srcs/main.c \
					srcs/new_split.c \
					srcs/libft_utils.c \
					srcs/list_utils.c \
					srcs/changedir.c \
					srcs/new_test.c

FLAGS			:=	-Wall -Wextra -Werror
OBJS			:=	$(SRCS:.c=.o)

all		: 	$(NAME)

%.o		:	%.c
			$(CC) -I ./includes/ -c $(FLAGS) -o $@ $<

$(NAME)	:	$(OBJS)
			$(CC) ${OBJS} $(FLAGS) -o $(NAME) -lreadline
			@echo $(NAME) has been made!

run		:	all
			./$(NAME)


leak	:	all
			valgrind --leak-check=full ./shell

clean	:
	    	$(RM) $(OBJS)

fclean	: 	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	re fclean clean run all
