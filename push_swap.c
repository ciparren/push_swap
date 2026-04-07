/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cintia <cintia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:47:48 by cintia            #+#    #+#             */
/*   Updated: 2026/02/18 17:55:23 by cintia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_info *info)
{
	info->a = malloc(sizeof(t_stack));
	info->b = malloc(sizeof(t_stack));
	if (!info->a || !info->b)
		exit(1);
	info->a->top = malloc(sizeof(t_node));
	info->b->top = malloc(sizeof(t_node));
	if (!info->a->top || !info->b->top)
		exit(1);
	info->a->top->next = info->a->top;
	info->a->top->prev = info->a->top;
	info->a->size = 0;
	info->b->top->next = info->b->top;
	info->b->top->prev = info->b->top;
	info->b->size = 0;
	ft_memset(info->ops, 0, sizeof(info->ops));
	info->total_ops = 0;
	info->bench = 0;
	info->strategy = ADAPTIVE;
}

static void	execute_strategy(t_info *info)
{
	if (info->strategy == SIMPLE)
		bubblesort(info);
	else if (info->strategy == MEDIUM)
		solve_medium(info);
	else if (info->strategy == COMPLEX)
		raddix(info);
	else
		solve_adaptive(info);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc < 2)
		return (0);
	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	init_stacks(info);
	parse_args(argc, argv, info);
	if (info->a->size > 0)
	{
		insert_index(info);
		info->disorder = compute_disorder(info->a);
		execute_strategy(info);
		if (info->bench)
			print_bench(info);
	}
	free_all(info);
	return (0);
}
