/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:03:26 by cintia            #+#    #+#             */
/*   Updated: 2026/04/07 12:00:00 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_info *info)
{
	t_node	*curr;

	curr = info->a->top->next;
	while (curr->next != info->a->top)
	{
		if (curr->index > curr->next->index)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	bubblesort(t_info *info)
{
	int	i;

	if (!info->a || info->a->size < 2 || is_sorted(info))
		return ;
	if (info->a->size == 2)
		return (solve_two(info));
	if (info->a->size == 3)
		return (solve_three(info));
	if (info->a->size == 4)
		return (solve_four(info));
	if (info->a->size == 5)
		return (solve_five(info));
	while (!is_sorted(info))
	{
		i = 0;
		while (i++ < info->a->size - 1)
		{
			if (info->a->top->next->index > info->a->top->next->next->index)
				sa(info);
			ra(info);
		}
		ra(info);
	}
	while (info->a->top->next->index != 0)
		ra(info);
}
