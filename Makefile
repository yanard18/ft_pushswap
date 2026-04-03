NAME	= push_swap
LIB_NAME = libpushswap.a
CC		= cc
CFLAGS	= -Wextra -Wall -Werror -I./inc

SRC_DIR	= src/
CORE_SRCS = $(addprefix $(SRC_DIR), parser/input_validate.c)
MAIN_SRC = $(addprefix $(SRC_DIR), main.c)
SRCS	= $(CORE_SRCS) $(MAIN_SRC)
OBJS	= $(SRCS:.c=.o)
CORE_OBJS = $(CORE_SRCS:.c=.o)

USE_GDB	= 0
ifeq ($(USE_GDB), 1)
	CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

lib: $(LIB_NAME)

$(LIB_NAME): $(CORE_OBJS)
	ar rcs $(LIB_NAME) $(CORE_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
