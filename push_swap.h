/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:44:33 by cintia            #+#    #+#             */
/*   Updated: 2026/03/30 10:29:41 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void				pa(t_info *info);
void				pb(t_info *info);
void				ra(t_info *info);
void				rb(t_info *info);
void				rr(t_info *info);
void				sa(t_info *info);
void				sb(t_info *info);
void				ss(t_info *info);
void				rra(t_info *info);
void				rrb(t_info *info);
void				rrr(t_info *info);
void				push_node(t_stack *stack, t_node *new_node);
void				swap_stack(t_stack *s);
void				append_node(t_info *info, int num);
int					check_dup(t_stack *a, int num);
void				error_exit(t_info *info);
void				process_number(char *str, t_info *info);
int					is_valid_number(char *arg);
int					is_flag(char *arg, t_info *info);
void				parse_args(int argc, char **argv, t_info *info);
void				free_stack(t_stack *stack);
float				compute_disorder(t_stack *a);
int					total_ops(t_info *info);
void				solve_simple(t_info *info);
void				solve_adaptive(t_info *info);
void				solve_medium(t_info *info);
long				ft_atol(const char *nptr);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
void				bubblesort(t_info *info);
long long			ft_sqrt(long long n);
void				print_bench(t_info *info);
t_node				*pop_node(t_stack *stack);
void				bench_disorder(t_info *info);
void				bench_strategy(t_info *info);
void				bench_ops(t_info *info);
void				bench_total_ops(t_info *info);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putfloat_fd(float nb, int decimals, int fd);
char				**ft_split(char const *s, char c);
void				chunksort(t_info *info);
void				free_matrix(char **matrix);
void				free_all(t_info *info);
void				error_split(t_info *info, char **args);
void				insert_index(t_info *info);
void				back_to_a(t_info *info);
int					get_max_pos(t_stack *b);
void				rotate_stack(t_stack *stack);
void				reverse_rotate_stack(t_stack *stack);
void				*ft_memset(void *s, int c, size_t n);
void				display_stack(t_stack *stack, char *name);
void				raddix(t_info *info);
int					is_sorted(t_info *info);
void				solve_two(t_info *info);
void				solve_three(t_info *info);
int					find_pos(t_info *info, int val);

#endif