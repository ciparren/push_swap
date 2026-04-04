/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:04:32 by ciparren          #+#    #+#             */
/*   Updated: 2026/03/30 09:57:00 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *s)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;

	if (s->size < 2)
		return ;
	first = s->top->next;
	second = first->next;
	if (s->size > 2)
	{
		last = s->top->prev;
		third = second->next;
		last->next = s->top;
		second->prev = s->top;
		third->prev = first;
		first->next = third;
		second->next = first;
		first->prev = second;
	}
	s->top->next = second;
}

void	sa(t_info *info)
{
	swap_stack(info->a);
	info->ops[5]++;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	swap_stack(info->b);
	info->ops[6]++;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	swap_stack(info->a);
	swap_stack(info->b);
	write(1, "ss\n", 3);
	info->ops[7]++;
}
