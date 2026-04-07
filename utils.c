/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:15:03 by cintia            #+#    #+#             */
/*   Updated: 2026/03/30 10:22:19 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	size_t	cont;
	int		signo;
	long	result;

	cont = 0;
	signo = 1;
	result = 0;
	while ((nptr[cont] >= 9 && nptr[cont] <= 13) || nptr[cont] == 32)
		cont++;
	if (nptr[cont] == '-' || nptr[cont] == '+')
	{
		if (nptr[cont] == '-')
			signo = -1;
		cont++;
	}
	while (nptr[cont] >= '0' && nptr[cont] <= '9')
	{
		result = (result * 10) + (nptr[cont] - '0');
		if (result > 2147483648)
			return (3000000000 * signo);
		cont++;
	}
	return (result * signo);
}

const char	*get_strategy_name(int strategy)
{
	if (strategy == SIMPLE)
		return ("Simple / O(n²)");
	else if (strategy == MEDIUM)
		return ("Medium / O(n√n)");
	else if (strategy == COMPLEX)
		return ("Complex / O(n log n)");
	else if (strategy == ADAPTIVE)
		return ("Adaptive / O(?)");
	else
		return ("Unknown");
}

void	display_stack(t_stack *stack, char *name)
{
	t_node	*curr;

	if (!stack || !stack->top)
		return ;
	printf("--- Stack %s (size: %d) ---\n", name, stack->size);
	curr = stack->top->next;
	if (curr == stack->top)
	{
		printf("Empty\n");
		printf("--------------------------\n");
		return ;
	}
	while (curr != stack->top)
	{
		printf("Val: %10d | Index: %d\n", curr->value, curr->index);
		curr = curr->next;
	}
	printf("--------------------------\n");
}

int	check_dup(t_stack *a, int num)
{
	t_node	*curr;

	curr = a->top->next;
	while (curr != a->top)
	{
		if (curr->value == num)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	get_min_pos(t_stack *a)
{
	t_node	*curr;
	int		min_idx;
	int		min_pos;
	int		i;

	curr = a->top->next;
	min_idx = curr->index;
	min_pos = 0;
	i = 0;
	while (i < a->size)
	{
		if (curr->index < min_idx)
		{
			min_idx = curr->index;
			min_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_pos);
}

void	push_min_to_b(t_info *info)
{
	int	pos;

	pos = get_min_pos(info->a);
	if (pos <= info->a->size / 2)
		while (pos-- > 0)
			ra(info);
	else
	{
		pos = info->a->size - pos;
		while (pos-- > 0)
			rra(info);
	}
	pb(info);
}
