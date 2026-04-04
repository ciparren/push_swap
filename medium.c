/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:17:47 by cintia            #+#    #+#             */
/*   Updated: 2026/03/26 11:22:53 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_medium(t_info *info)
{
	chunksort(info);
	back_to_a(info);
}

void	chunksort(t_info *info)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(info->a->size) * 1.5;
	while (info->a->size > 0)
	{
		if (info->a->top->next->index <= i + range)
		{
			pb(info);
			if (info->b->size > 1 && info->b->top->next->index <= i)
				rb(info);
			i++;
		}
		else
			ra(info);
	}
}

long long	ft_sqrt(long long n)
{
	long long	inicio;
	long long	fin;
	long long	ans;
	long long	mid;

	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	inicio = 1;
	fin = n;
	while (inicio <= fin)
	{
		mid = (inicio + fin) / 2;
		if (mid * mid == n)
		{
			return (mid);
		}
		if (mid * mid < n)
		{
			inicio = mid + 1;
			ans = mid;
		}
		else
		{
			fin = mid - 1;
		}
	}
	return (ans);
}

int	get_max_pos(t_stack *b)
{
	t_node	*curr;
	int		max_idx;
	int		pos;
	int		i;

	curr = b->top->next;
	max_idx = curr->index;
	pos = 0;
	i = 0;
	while (i < b->size)
	{
		if (curr->index > max_idx)
		{
			max_idx = curr->index;
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos);
}

void	back_to_a(t_info *info)
{
	int	max_pos;

	while (info->b->size > 0)
	{
		max_pos = get_max_pos(info->b);
		if (max_pos <= info->b->size / 2)
		{
			while (max_pos-- > 0)
				rb(info);
		}
		else
		{
			max_pos = info->b->size - max_pos;
			while (max_pos-- > 0)
				rrb(info);
		}
		pa(info);
	}
}
