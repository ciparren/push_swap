# Makefile para pruebas de benchmark
NAME = push_swap_bench
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

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
       ft_libc.c  # <-- AÑADIDO

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

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