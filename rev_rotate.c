/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:00:13 by cintia            #+#    #+#             */
/*   Updated: 2026/03/25 18:00:37 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	if (!stack || stack->size < 2)
		return ;
	last = stack->top->prev;
	first = stack->top->next;
	last->prev->next = stack->top;
	stack->top->prev = last->prev;
	last->next = first;
	last->prev = stack->top;
	stack->top->next = last;
	first->prev = last;
}

void	rra(t_info *info)
{
	reverse_rotate_stack(info->a);
	write(1, "rra\n", 4);
	info->ops[8]++;
}

void	rrr(t_info *info)
{
	reverse_rotate_stack(info->a);
	reverse_rotate_stack(info->b);
	write(1, "rrr\n", 4);
	info->ops[10]++;
}

