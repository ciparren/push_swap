/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:15:36 by cintia            #+#    #+#             */
/*   Updated: 2026/03/25 18:01:05 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_info *info)
{
	t_node	*tmp;

	if (info->a->size == 0)
		return ;
	tmp = pop_node(info->a);
	push_node(info->b, tmp);
	info->ops[1]++;
	write(1, "pb\n", 3);
}

void	pa(t_info *info)
{
	t_node	*tmp;

	if (info->b->size == 0)
		return ;
	tmp = pop_node(info->b);
	push_node(info->a, tmp);
	info->ops[0]++;
	write(1, "pa\n", 3);
}

t_node	*pop_node(t_stack *stack)
{
	t_node	*to_pop;

	if (stack->size == 0)
		return (NULL);
	to_pop = stack->top->next;
	stack->top->next = to_pop->next;
	to_pop->next->prev = stack->top;
	stack->size--;
	to_pop->next = NULL;
	to_pop->prev = NULL;
	return (to_pop);
}

void	push_node(t_stack *stack, t_node *new_node)
{
	t_node	*old_first;

	if (!new_node)
		return ;
	old_first = stack->top->next;
	new_node->next = old_first;
	new_node->prev = stack->top;
	stack->top->next = new_node;
	old_first->prev = new_node;
	stack->size++;
}
