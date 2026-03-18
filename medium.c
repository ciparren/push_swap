/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:17:47 by cintia            #+#    #+#             */
/*   Updated: 2026/03/18 10:14:59 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void solve_medium(t_info *info)
{
    chunksort(info);
}

void chunksort(t_info *info)
{
    int chunk; // redondeaos abajo, más sencillo, ara calcular los trozos que vamos a usar
    int curr_chunk;
    // ahora hay que ir cogiendo esos chunks hasta llegar a size completo de a e ir pasando a la pila B.
    
    if(!info->a || info->a->size < 2)
        return ;
    chunk =  ft_sqrt(info->a->size);
    if(chunk == 0)
        chunk = 1;
    while(info->a->size > 0)
    {
        if(info->a->top->index < curr_chunk * chunk)
            pb(info);
        else
            ra(info);
        if(info->a->size > 0 && info->a->top->index >= curr_chunk * chunk)
            curr_chunk++;
    }
}

// Función para calcular la raíz cuadrada entera
long long  ft_sqrt(long long n) {

    long long inicio;
    long long fin; 
    long long ans;

    if (n < 0) return -1; 
    if (n == 0 || n == 1) return n;

    
    inicio = 1;
    fin = n;
    
    while (inicio <= fin) {
        long long mid = (inicio + fin) / 2;

        if (mid * mid == n) {
            return mid;
        }

        if (mid * mid < n) {
            inicio = mid + 1;
            ans = mid; 
        } else {
            fin = mid - 1;
        }
    }
    return ans;
}
/*
static int find_max(t_stack *b)
{
    t_node *curr;
    int max_value;
    int max_pos;
    int i;

    if(!b || b->size == 0)
        return (-1);
    curr = b->top;
    max_value = curr->index;
    max_pos = 0;
    i = 0;

    while(i < b->size)
    {
        if(curr->index > max_value)
        {
            max_value = curr->index;
            max_pos = i;
        }
        curr = curr->next;
        i++;
    }
    return (max_pos);
}

static void rot_max(t_info *info, int max_pos)
{
    int size;
    int i;

    size = info->b->size;

    if(max_pos <= size / 2)
    {
        i = 0;
        while(i < max_pos)
        {
            rb(info);
            i++;
        }
    }
    else
    {
        i = 0;
        while(i < size - max_pos)
        {
            rrb(info);
            i++;
        }
    }
}
    */