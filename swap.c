/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:04:32 by ciparren          #+#    #+#             */
/*   Updated: 2026/03/13 09:55:51 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_info *info)
{
    t_node *first;
    t_node *second;
    t_node *third;
    t_node *last;

    if(info->a->size < 2)
        return ;
    first = info->a->top->next;
    second = first->next;
    if(info->a->size > 2)
    {
        last = info->a->top->prev;
        third = second->next;
        last->next = info->a->top;  // es nuestro top
        second->prev = info->a->top;
        third->prev = first;
        first->next = third;
        second->next = first;
        first->prev = second;
    }
    info->a->top->next = second;
    info->ops[5]++;
    write(1, "sa\n", 3);
}

void    sb(t_info *info)
{
    t_node *first;
    t_node *second;
    t_node *third;
    t_node *last;

    if(info->b->size < 2)
        return ;
    first = info->b->top->next;
    second = first->next;
    if(info->b->size > 2)
    {
        last = first->prev;
        third = second->next;
        last->next = second;
        second->prev = last;
        third->prev = first;
        first->next = third;
        second->next = first;
        first->prev = second;
    }   
    info->b->top->next->next = second;
    info->ops[6]++;
    write(1, "sb\n", 3);
}

void    ss(t_info *info)
{
    sa(info);
    sb(info);
    write(1, "ss\n", 3);
    info->ops[7]++;
    // TODO ahora mismo imprime: sa, sb, ss.
}
