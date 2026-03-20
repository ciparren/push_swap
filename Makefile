# Makefile para pruebas de benchmark
NAME = push_swap_bench
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Ruta de la libft (ajusta si es necesario)
LIBFT_DIR = ft_libc
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
       parser.c \
       push.c \
       swap.c \
       rotate.c \
       rev_rotate.c \
       simple.c \
       medium.c \
       adaptive.c \
       complex.c \
       disorder.c \
       ft_total_ops.c \
       utils.c \
       benchmark.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Compilar la libft antes
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

test: $(NAME)
	@echo "\n=== EJECUTANDO PRUEBAS ===\n"
	@./$(NAME)

test-redirect: $(NAME)
	@echo "\n=== PRUEBA CON REDIRECCIÓN ===\n"
	@./$(NAME) 2> bench_output.txt
	@echo "Benchmark guardado en bench_output.txt"
	@cat bench_output.txt

.PHONY: all clean fclean re test test-redirect