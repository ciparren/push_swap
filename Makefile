NAME        = push_swap
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
LIBFT_DIR   = ft_libc
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = main.c parser.c push.c swap.c rotate.c rev_rotate.c \
              simple.c medium.c adaptive.c disorder.c error_manager.c \
              ft_total_ops.c utils.c benchmark.c
OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

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