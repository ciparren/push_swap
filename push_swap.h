/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:44:33 by cintia            #+#    #+#             */
/*   Updated: 2026/03/18 10:22:07 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NO DEBE HACER RELINK

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

// DEFINICIÓN DE ESTRATEGIAS
# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3

// LISTA DOBLEMENTE ENLAZADA
// Cómo es el nodo por dentro
typedef struct s_node
{
    int             value;
    int             index;  
    struct s_node   *next;
    struct s_node   *prev;
} t_node;
// Cómo es la pila
typedef struct s_stack
{
    t_node  *top; // como si fuese mi head
    int     size;
} t_stack;

// información de salida
typedef struct s_info
{
    t_stack *a; // declaro mi pila a
    t_stack *b; // declaro mi pila b
    int     ops[11];  /*pa, pb, ra, rb, rr, sa, sb, ss, rra, rrb, rrr,  */
    int     total_ops;// 0  1    2   3   4   5   6  7    8    9    10 
    float   disorder;  
    int     bench;    /* Indica si --bench está activo */
    int     strategy; // estrategia elegida, simple, medium, complex, adaptive...
}   t_info;

// PROTOTIPOS DE FUNCIONES
void    pa(t_info *info);
void    pb(t_info *info);

void    ra(t_info *info);
void    rb(t_info *info);
void    rr(t_info *info);

void    sa(t_info *info);
void    sb(t_info *info);
void    ss(t_info *info);

void    rra(t_info *info);
void    rrb(t_info *info);
void    rrr(t_info *info);

void push_node(t_stack *stack, t_node *new_node);

// PARSER
void append_node(t_info *info, int num);
int check_dup(t_stack *a, int num);
void error_exit(t_info *info);
void process_number(char *str, t_info *info);
int is_valid_number(char *arg);
int is_flag(char *arg, t_info *info);
void parse_args(int argc, char **argv, t_info *info);
void free_stack(t_stack *stack);

float compute_disorder(t_stack *a);
int total_ops(t_info *info);

void    solve_simple(t_info *info);
void    solve_adaptive(t_info *info);
void    solve_medium(t_info *info);
void    solve_complex(t_info *info);

// auxiliares
long     ft_atol(const char *nptr);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_isdigit(int c);
void bubblesort(t_info *info);
long long ft_sqrt(long long n);

// benchmark
void print_bench(t_info *info);
t_node *pop_node(t_stack *stack);
void bench_disorder(t_info *info);
void bench_strategy(t_info *info);
void bench_ops(t_info *info);   
void bench_total_ops(t_info *info);

// Añadir al final de push_swap.h, antes del #endif

// Funciones de libc
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putfloat_fd(float num, int fd, int precision);



void chunksort(t_info *info);



#endif