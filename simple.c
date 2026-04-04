/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:03:26 by cintia            #+#    #+#             */
/*   Updated: 2026/03/30 10:13:51 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO hacer un algoritmo que resuelva cuando tiene solo 2,
// 3 y 5 números la pila

void	bubblesort(t_info *info)
{
	int	i;
	int	swapped;

	if (!info->a || info->a->size < 2)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < info->a->size - 1)
		{
			if (info->a->top->next->index > info->a->top->next->next->index)
			{
				sa(info);
				swapped = 1;
			}
			ra(info);
			i++;
		}
		ra(info);
	}
	while (info->a->top->next->index != 0)
		ra(info);
}
