/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:17:47 by cintia            #+#    #+#             */
/*   Updated: 2026/03/30 10:21:47 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // TODO

/*
void solve_complex(t_info *info)
{
    // Implementación O(n log n)
    // Ejemplo: radix sort
}
*/

#include "push_swap.h"

void	raddix(t_info *info)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = info->a->size;
	max_bits = 0;
	// 1. Calculamos cuántos bits necesitamos para el número más grande (size - 1)
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	// 2. Iteramos bit a bit
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			// 3. Si el bit i-ésimo del índice es 1, se queda en A. Si es 0, va a B.
			if (((info->a->top->next->index >> i) & 1) == 1)
				ra(info);
			else
				pb(info);
		}
		// 4. Devolvemos todo de B a A manteniendo el orden relativo (FIFO)
		while (info->b->size > 0)
			pa(info);
		i++;
	}
}