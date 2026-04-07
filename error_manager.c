/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:15:03 by cintia            #+#    #+#             */
/*   Updated: 2026/03/26 11:23:06 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_info *info)
{
	if (!info)
		return ;
	if (info->a)
	{
		free_stack(info->a);
	}
	if (info->b)
	{
		free_stack(info->b);
	}
}

void	error_exit(t_info *info)
{
	write(2, "Error\n", 6);
	free_all(info);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*next_node;

	if (!stack)
		return ;
	curr = stack->top->next;
	while (curr != stack->top)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
	free(stack->top);
	free(stack);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	error_split(t_info *info, char **args)
{
	free_matrix(args);
	error_exit(info);
}
