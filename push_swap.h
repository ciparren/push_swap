/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:17:47 by cintia            #+#    #+#             */
/*   Updated: 2026/03/26 17:21:42 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_libc/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_info
{
	t_stack			*a;
	t_stack			*b;
	int				ops[11];
	int				total_ops;
	float			disorder;
	int				bench;
	int				strategy;
}					t_info;

/* parser.c */
void				parse_args(int argc, char **argv, t_info *info);
int					is_flag(char *arg, t_info *info);
int					is_valid_number(char *arg);
void				process_number(char *str, t_info *info);
void				append_node(t_info *info, int num);

/* error_manager.c */
void				free_all(t_info *info);
void				error_exit(t_info *info);
void				free_stack(t_stack *stack);
void				free_matrix(char **matrix);
void				error_split(t_info *info, char **args);

/* push.c */
void				pa(t_info *info);
void				pb(t_info *info);
t_node				*pop_node(t_stack *stack);
void				push_node(t_stack *stack, t_node *new_node);

/* swap.c */
void				swap_stack(t_stack *s);
void				sa(t_info *info);
void				sb(t_info *info);
void				ss(t_info *info);

/* rotate.c */
void				rotate_stack(t_stack *stack);
void				ra(t_info *info);
void				rb(t_info *info);
void				rr(t_info *info);

/* rev_rotate.c */
void				reverse_rotate_stack(t_stack *stack);
void				rra(t_info *info);
void				rrb(t_info *info);
void				rrr(t_info *info);

/* simple.c */
int					is_sorted(t_info *info);
void				bubblesort(t_info *info);

/* adaptive.c */
int					get_min_pos(t_stack *a);
void				push_min_to_b(t_info *info);
void				solve_four(t_info *info);
void				solve_five(t_info *info);
void				solve_two(t_info *info);
void				solve_three(t_info *info);
void				solve_adaptive(t_info *info);

/* medium.c */
void				solve_medium(t_info *info);
void				chunksort(t_info *info);
long long			ft_sqrt(long long n);
int					get_max_pos(t_stack *b);
void				back_to_a(t_info *info);

/* complex.c */
void				raddix(t_info *info);

/* disorder.c */
float				compute_disorder(t_stack *a);

/* benchmark.c */
void				print_bench(t_info *info);
void				bench_disorder(t_info *info);
void				bench_strategy(t_info *info);
void				bench_total_ops(t_info *info);
void				bench_ops(t_info *info);

int					total_ops(t_info *info);
void				insert_index(t_info *info);

/* utils.c */
long				ft_atol(const char *nptr);
const char			*get_strategy_name(int strategy);
void				display_stack(t_stack *stack, char *name);
int					check_dup(t_stack *a, int num);

#endif