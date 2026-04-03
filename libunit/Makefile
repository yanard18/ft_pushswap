CC           = cc
CFLAGS       = -Wextra -Wall -Werror -Wno-format
INCLUDES     = -I./inc

MAKE         = make
NAME         = run
SRCS         = unit.c test_basic.c
HEADERS      = unit.h

all: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	make fclean -C $(FTPRINTF_DIR)

FORCE:

.PHONY: all clean fclean FORCE

