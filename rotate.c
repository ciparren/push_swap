/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:59:22 by cintia            #+#    #+#             */
/*   Updated: 2026/03/25 17:00:42 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Shift up all elements of stack a by one. The first element becomes the last one.

void    rotate_stack(t_stack *stack)
{
    t_node  *first;
    t_node  *last;

    if (!stack || stack->size < 2)
        return ;
    first = stack->top->next;
    last = stack->top->prev;
    stack->top->next = first->next;
    first->next->prev = stack->top;
    last->next = first;
    first->prev = last;
    first->next = stack->top;
    stack->top->prev = first;
}

void    ra(t_info *info)
{
    rotate_stack(info->a);
    write(1, "ra\n", 3);
    info->ops[2]++;
}

void    rb(t_info *info)
{
    rotate_stack(info->b);
    write(1, "rb\n", 3);
    info->ops[3]++;
}

void    rr(t_info *info)
{
    rotate_stack(info->a);
    rotate_stack(info->b);
    write(1, "rr\n", 3);
    info->ops[4]++;
}
