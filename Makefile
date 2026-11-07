NAME = libftprintf.a

SRCS = src/ft_printnumber.c src/ft_printchar.c src/ft_printstring.c \
	src/ft_printaddress.c src/ft_printhexa_upper.c src/ft_printhexa_lower.c \
	src/ft_printunsigned.c src/ft_printf.c
OBJS = $(SRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I
HDR = ./headers

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c ./headers/ft_printf.h
	@$(CC) $(CFLAGS) $(HDR) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re