/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:15:03 by cintia            #+#    #+#             */
/*   Updated: 2026/03/25 16:31:32 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc/libft.h"
#include "push_swap.h"

void	print_bench(t_info *info)
{
	bench_disorder(info);
	bench_strategy(info);
	bench_total_ops(info);
	bench_ops(info);
}

void	bench_disorder(t_info *info)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putfloat_fd(info->disorder * 100, 2, 2);
	ft_putstr_fd("%\n", 2);
}

void	bench_strategy(t_info *info)
{
	if (info->strategy == ADAPTIVE)
	{
		ft_putstr_fd("[bench] strategy: Adaptative / ", 2);
		if (info->disorder < 0.2f)
			ft_putstr_fd("O(n²)\n", 2);
		else if (info->disorder < 0.5f)
			ft_putstr_fd("O(n√n)\n", 2);
		else
			ft_putstr_fd("O(n log n)\n", 2);
	}
	else if (info->strategy == SIMPLE)
	{
		ft_putstr_fd("[bench] strategy: Simple / O(n²)\n", 2);
	}
	else if (info->strategy == MEDIUM)
	{
		ft_putstr_fd("[bench] strategy: Medium / O(n√n)\n", 2);
	}
	else if (info->strategy == COMPLEX)
	{
		ft_putstr_fd("[bench] strategy: Complex / O(n log n)\n", 2);
	}
}

void	bench_total_ops(t_info *info)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total_ops(info), 2);
	ft_putstr_fd("\n", 2);
}

void	bench_ops(t_info *info)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(info->ops[5], 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(info->ops[6], 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(info->ops[7], 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(info->ops[0], 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(info->ops[1], 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(info->ops[2], 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(info->ops[3], 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(info->ops[4], 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(info->ops[8], 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(info->ops[9], 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(info->ops[10], 2);
	ft_putstr_fd("\n", 2);
}
