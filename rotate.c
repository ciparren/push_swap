/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:59:22 by cintia            #+#    #+#             */
/*   Updated: 2026/03/18 09:31:40 by ciparren         ###   ########.fr       */
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

// TODO
// En rr() estás haciendo return prematuro:
void    rr(t_info *info)
{
    if(!info->a || info->a->size < 2)  // Si falla A, no hace B
        return ;                        // ¡ERROR! Debe intentar B igualmente
    info->a->top = info->a->top->next;
    if(!info->b || info->b->size < 2)   // Si falla B, no imprime rr
        return ;                        // ¡ERROR!
    info->b->top = info->b->top->next;
    write(1, "rr\n", 3);
    info->ops[4]++;
}
