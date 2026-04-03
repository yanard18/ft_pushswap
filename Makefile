NAME	= push_swap.a
CC		= cc
CFLAGS	= -Wextra -Wall -Werror -I./inc

SRC_DIR	= src/
SRCS	= $(addprefix $(SRC_DIR), main.c)
OBJS	= $(SRCS:.c=.o)

USE_GDB	= 0
ifeq ($(USE_GDB), 1)
	CFLAGS += -g
endif

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
