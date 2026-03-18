/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:15:36 by cintia            #+#    #+#             */
/*   Updated: 2026/03/18 09:29:39 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Take the first element at the top of a and put it at the top of b. Do nothing if a is empty
void    pb(t_info *info)
{
    t_node	*tmp;

	if (info->a->size == 0)
		return ;
	tmp = pop_node(info->a);
	push_node(info->b, tmp);
	info->ops[1]++; 
	write(1, "pb\n", 3);
}

// Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
void    pa(t_info *info)
{
    t_node	*tmp;

	if (info->b->size == 0)
		return ;
	tmp = pop_node(info->b);
	push_node(info->a, tmp);
	info->ops[0]++; 
	write(1, "pa\n", 3);
}

t_node *pop_node(t_stack *stack)
{
    t_node *to_pop;

    if(!stack->top)
        return (NULL);
    to_pop = stack->top;
    if(stack->size == 1)
        stack->top = NULL;
    else
    {
        to_pop->prev->next = to_pop->next;
        to_pop->next->prev = to_pop->prev;
    }
    stack->size--;
    // por si acaso, aislamos el nodo
    to_pop->next = NULL;
    to_pop->prev = NULL;
    return (to_pop);
}

void push_node(t_stack *stack, t_node *new_node)
{
    t_node *last;

    if(!new_node)
        return ;
    if(stack->size == 0)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else
    {
        last = stack->top->prev;
        new_node->next = stack->top;
        new_node->prev = last;
        last->next = new_node;
        stack->top->prev = new_node;
    }
    stack->top = new_node;
    stack->size++;
}
