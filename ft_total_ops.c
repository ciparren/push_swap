/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamercha <gamercha@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:15:03 by gamercha           #+#    #+#            */
/*   Updated: 2026/03/13 11:47:28 by gamercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	total_ops(t_info *info)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		info->total_ops += info->ops[i];
		i++;
	}
	return (info->total_ops);
}
