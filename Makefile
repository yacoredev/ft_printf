NAME = libftprintf.a
BONUS_NAME = .bonus

SRCS = srcs/ft_printf.c \
	srcs/ft_printnumber.c \
	srcs/ft_printchar.c \
	srcs/ft_printstring.c \
	srcs/ft_printaddress.c \
	srcs/ft_printhexa_upper.c \
	srcs/ft_printhexa_lower.c \
	srcs/ft_printunsigned.c

SHARED_SRCS = srcs/ft_printchar.c \
	srcs/ft_printstring.c \
	srcs/ft_printunsigned.c

BONUS_SRCS = srcs/ft_printf_bonus.c \
	srcs/ft_printnumber_bonus.c \
	srcs/ft_printaddress_bonus.c \
	srcs/ft_printhexa_upper_bonus.c \
	srcs/ft_printhexa_lower_bonus.c

OBJS = $(SRCS:%.c=%.o)
SHARED_OBJS = $(SHARED_SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I
HDR = ./headers

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(SHARED_OBJS) $(BONUS_OBJS)
	rm -f $(NAME)
	ar rcs $(NAME) $(SHARED_OBJS) $(BONUS_OBJS)
	touch $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HDR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re