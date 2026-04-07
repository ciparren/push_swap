/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciparren <ciparren@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:14:06 by cintia            #+#    #+#             */
/*   Updated: 2026/03/30 10:09:47 by ciparren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(int argc, char **argv, t_info *info)
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i++], info))
			continue ;
		args = ft_split(argv[i], ' ');
		if (!args)
			error_exit(info);
		j = 0;
		while (args[j])
		{
			if (is_valid_number(args[j]))
				process_number(args[j], info);
			else
				error_split(info, args);
			j++;
		}
		free_matrix(args);
		i++;
	}
}

int	is_flag(char *arg, t_info *info)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
		info->bench = 1;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		info->strategy = ADAPTIVE;
	else if (ft_strncmp(arg, "--simple", 9) == 0)
		info->strategy = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		info->strategy = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		info->strategy = COMPLEX;
	else
		return (0);
	return (1);
}

int	is_valid_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i] == '\0')
		return (0);
	while ((arg[i]))
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void	process_number(char *str, t_info *info)
{
	long	num;

	num = ft_atol(str);
	if (num > 2147483647 || num < -2147483648)
		error_exit(info);
	if (check_dup(info->a, (int)num))
		error_exit(info);
	append_node(info, (int)num);
}

void	append_node(t_info *info, int num)
{
	t_node	*to_append;
	t_node	*last;

	to_append = malloc(sizeof(t_node));
	if (!to_append)
		error_exit(info);
	to_append->value = num;
	last = info->a->top->prev;
	to_append->next = info->a->top;
	to_append->prev = last;
	last->next = to_append;
	info->a->top->prev = to_append;
	info->a->size++;
}
