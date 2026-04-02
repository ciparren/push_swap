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

/*
void	solve_simple(t_info *info)
{
	// Tu implementación O(n²)
	// Puede ser bubblesort u otro algoritmo simple
}
*/

// TODO hacer un algoritmo que resuelva cuando tiene solo 2,
	//3 y 5 números la pila

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
		// Solo iteramos hasta size
		//- 1 para no comparar el último con el fantasma
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
		// Hacemos una rotación extra para devolver la pila a su sitio y cerrar el ciclo
		ra(info);
	}
	// Asegurar que el 0 quede arriba
	while (info->a->top->next->index != 0)
		ra(info);
}

/*
void	bubblesort(t_info *info)
{
	int	i;
	int	j;
	int	swap;

	if (!info->a || info->a->size < 2)
		return ;
	i = 0;
	while (i < info->a->size - 1)
	{
		swap = 0;
		j = 0;
		while (j < info->a->size - 1 - i) // no tenía el - i
		{
			if (info->a->top->next->value > info->a->top->next->next->value)
			{
				sa(info);
				swap = 1;
			}
			ra(info);
			j++;
		}
		ra(info);
		if (!swap)
			break ;
		i++;
	}
}
	*/

/*
void	bubblesort(t_info *info)
{
	int		i;
	int		j;
	int		swapped;
	t_node	*current;

	if (!info->a || info->a->size < 2)
		return ;
	i = 0;
	while (i < info->a->size - 1)
	{
		swapped = 0;
		j = 0;
		current = info->a->top;
		while (j < info->a->size - 1 - i)
		{
			if (current->value > current->next->value)
			{
				sa(info);
				swapped = 1;
			}
			ra(info);
			current = info->a->top;
			j++;
		}
		// Al final de cada pasada, el elemento más grande está al final
		// Necesitamos rotar para traer el inicio de nuevo al tope
		// Pero como hemos estado rotando, nuestro "current" ya está en posición
		if (!swapped)
			break ;
		i++;
	}
	// Asegurar que el mínimo quede al tope
	while (info->a->top->value > info->a->top->next->value)
		ra(info);
}
*/