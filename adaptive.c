/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:17:47 by cintia            #+#    #+#             */
/*   Updated: 2026/03/30 10:22:03 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_adaptive(t_info *info)
{
	if (info->disorder < 0.2f)
	{
		bubblesort(info);
	}
	else if (info->disorder < 0.5f)
	{
		solve_medium(info);
	}
	else
	{
		raddix(info);
	}
}

void	solve_four(t_info *info)
{
	pb(info);
	solve_three(info);
	find_and_insert(info);
}

void	solve_five(t_info *info)
{
	pb(info);
	pb(info);
	solve_three(info);
	find_and_insert(info);
	find_and_insert(info);
}

void	solve_two(t_info *info)
{
	if (info->a->top->next->index > info->a->top->next->next->index)
		sa(info);
}

void	solve_three(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->a->top->next->index;
	b = info->a->top->next->next->index;
	c = info->a->top->next->next->next->index;
	if (a > b && b < c && a < c)
		return (sa(info));
	if (a > b && b > c)
		return (sa(info), rra(info));
	if (a > b && b < c && a > c)
		return (ra(info));
	if (a < b && b > c && a < c)
		return (sa(info), ra(info));
	if (a < b && b > c && a > c)
		return (rra(info));
}
