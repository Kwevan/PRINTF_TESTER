NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c \
	utils/utils_string.c \
	utils/utils_number.c \
	print/print_string.c \
	print/print_number.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
	@gcc ${FLAGS} -I ft_printf.h -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
