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

void	raddix(t_info *info)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = info->a->size;
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((info->a->top->next->index >> i) & 1) == 1)
				ra(info);
			else
				pb(info);
		}
		while (info->b->size > 0)
			pa(info);
		i++;
	}
}
