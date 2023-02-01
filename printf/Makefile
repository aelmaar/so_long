OBJS = ft_printf.o ft_putchar.o ft_puthex.o ft_putnbr.o ft_putptr.o ft_putstr.o ft_putunbr.o ft_write.o

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

NAME = libftprintf.a

AR = ar -rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $?

%.o: %.c
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean