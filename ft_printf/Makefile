NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

HEADER = include

SRC_PATH = src

SRC_FILES = ft_printf.c \
	utils_string.c \
	utils_number.c \
	print_string.c \
	print_number.c \
	get_flags.c \
	conv_d.c \
	conv_s.c \
	conv_1.c \
	conv_2.c \
	utils_flags.c

SRCS = $(addprefix ${SRC_PATH}/, ${SRC_FILES})

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		@ar -rcs $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
	@gcc ${FLAGS} -I ${HEADER} -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
