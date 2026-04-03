NAME	= run
CC		= cc
CFLAGS	= -Wextra -Wall -Werror -I../inc -I../libunit/inc

SRCS	= test_parser.c
OBJS	= $(SRCS:.c=.o)

PS_LIB	= ../libpushswap.a
UNIT_LIB	= ../libunit/libunit.a

all: $(NAME)

$(NAME): $(OBJS) $(PS_LIB) $(UNIT_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L.. -lpushswap -L../libunit -lunit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PS_LIB): FORCE
	@$(MAKE) -C ../ lib

$(UNIT_LIB): FORCE
	@$(MAKE) -C ../libunit

clean:
	rm -f $(OJBS)

fclean: clean
	rm -f $(NAME)

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
