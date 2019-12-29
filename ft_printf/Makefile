NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(SRCS) $(OBJS)
		gcc $(FLAGS) -c ft_printf.h $(SRCS)
		ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
