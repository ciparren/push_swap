/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:59:22 by cintia            #+#    #+#             */
/*   Updated: 2026/03/07 11:04:23 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Shift up all elements of stack a by one. The first element becomes the last one.
void    ra(t_info *info)
{
    if(!info->a || info->a->size < 2)
        return ;
    info->a->top = info->a->top->next;
    info->ops[2]++;
    write(1, "ra\n", 3);
}

void    rb(t_info *info)
{
    if(!info->b || info->b->size < 2)
        return ;
    info->b->top = info->b->top->next;
    write(1, "rb\n", 3);
    info->ops[3]++;
}

void    rr(t_info *info)
{
    // si hago esto me está sumando por cada llamada un ++ a cada op e imprime 3 veces
    // rb(info);
    // ra(info);
    // write(1, "rr\n", 3);
    // info->ops[4]++;
    if(!info->a || info->a->size < 2)
        return ;
    info->a->top = info->a->top->next; //tenía puesto prev
     if(!info->b || info->b->size < 2)
        return ;
    info->b->top = info->b->top->next;
    write(1, "rr\n", 3);
    info->ops[4]++;
}