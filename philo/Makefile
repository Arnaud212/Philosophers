NAME	= 	philo

HEADER	= 	./includes/philo.h

CC		= 	gcc

LFLAGS  =   -lpthread

CFLAGS	= 	-Wall -Wextra -Werror -g -I $(HEADER)

SRCS	=	./srcs/main.c \
			./srcs/lib_utils.c \
			./srcs/ft_print.c \
			./srcs/ft_life_eat.c \
			./srcs/ft_isdigit.c \
			./srcs/ft_atoi.c

OBJS	=	$(SRCS:.c=.o)

all: 	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re