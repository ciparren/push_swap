NAME        = push_swap
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
LIBFT_DIR   = ft_libc
LIBFT       = $(LIBFT_DIR)/libft.a

# Todos los archivos .c que hemos revisado
SRCS        = parser.c push_swap.c push.c swap.c rotate.c rev_rotate.c \
              simple.c medium.c complex.c adaptive.c disorder.c \
              error_manager.c ft_total_ops.c utils.c benchmark.c

OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Incluimos -I. para push_swap.h y -I$(LIBFT_DIR) para libft.h
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re