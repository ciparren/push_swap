/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:17:47 by cintia            #+#    #+#             */
/*   Updated: 2026/03/26 17:21:42 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Function compute_disorder(stack a):
    mistakes = 0
    total_pairs = 0
    for i from 0 to size(a)-1:
    for j from i+1 to size(a)-1:
    total_pairs += 1
    if a[i] > a[j]:
    mistakes += 1
return mistakes / total_pairs 
*/
#include "push_swap.h"

float	compute_disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total_pairs;

	if (a->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = a->top->next; 
	while (i != a->top)
	{
		j = i->next;
		while (j != a->top)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((float)mistakes / (float)total_pairs);
}

/*
float compute_disorder(t_stack *a)
{
    t_node  *i;
    t_node  *j;
    long    mistakes;   // Contador de errores
    long    total_pairs;// Total de combinaciones

    if(a->size < 2)
        return (0.0);
    mistakes = 0;
    total_pairs = 0;
    i = a->top; 
    while(i->next != a->top)
    {
        j = i->next;
        while(j != a->top)
        {
            total_pairs++;
            if(i->value > j->value)
                mistakes++;
            j = j->next;
        }
        i = i->next;
    }
    if(total_pairs == 0)
        return  (0.0);
    return (mistakes / total_pairs);
}
*/
