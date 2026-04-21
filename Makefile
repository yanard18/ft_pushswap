NAME	= push_swap
LIB_NAME = libpushswap.a
CC		= cc
CFLAGS	= -Wextra -Wall -Werror -I./inc -I./libft/inc


SRC_DIR	= src/
CORE_SRCS = $(addprefix $(SRC_DIR), parser/input_validate.c \
		parser/parser.c \
		strategies/sort.c \
		strategies/sort_adaptive.c \
		stack.c \
		strategies/sort_complex.c \
		operations/op_push_swap.c \
		operations/op_rotate.c \
		operations/op_reverse_rotate.c \
		benchmark.c \
		disorder.c)
MAIN_SRC = $(addprefix $(SRC_DIR), main.c)
SRCS	= $(CORE_SRCS) $(MAIN_SRC)
OBJS	= $(SRCS:.c=.o)
CORE_OBJS = $(CORE_SRCS:.c=.o)

FT_LIB      = ./libft/libft.a

USE_GDB	= 0
ifeq ($(USE_GDB), 1)
	CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(FT_LIB) -o $(NAME)

lib: $(LIB_NAME)

$(LIB_NAME): $(CORE_OBJS)
	ar rcs $(LIB_NAME) $(CORE_OBJS)

$(FT_LIB): FORCE
	@$(MAKE) -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
