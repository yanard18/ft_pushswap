NAME	= run
CC		= cc
CFLAGS	= -Wextra -Wall -Werror -I../inc -I../libunit/inc -I../libft/inc -g

SRCS	= test_parser.c
OBJS	= $(SRCS:.c=.o)

PS_LIB	= ../libpushswap.a
UNIT_LIB	= ../libunit/libunit.a
FT_LIB      = ../libft/libft.a

all: $(NAME)
	valgrind --leak-check=full ./run

$(NAME): $(OBJS) $(PS_LIB) $(UNIT_LIB) $(FT_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L.. -lpushswap -L../libunit -lunit -L../libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PS_LIB): FORCE
	@$(MAKE) USE_GDB=1 -C ../ lib

$(UNIT_LIB): FORCE
	@$(MAKE) -C ../libunit

$(FT_LIB): FORCE
	@$(MAKE) -C ../libft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
