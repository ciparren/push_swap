/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamercha <gamercha@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 18:15:03 by gamercha           #+#    #+#            */
/*   Updated: 2026/03/13 11:47:28 by gamercha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>

static void	ft_putint_fd_rec(long long nb, int fd)
{
	char	c;

	if (nb > 9)
		ft_putint_fd_rec(nb / 10, fd);
	c = '0' + nb % 10;
	write(fd, &c, 1);
}

static void	ft_putdec_fd_rec(long long nb, int decimals, int fd)
{
	char	c;
	int		factor;
	int		i;

	if (decimals == 0)
		return ;
	factor = 1;
	i = 1;
	while (i < decimals)
	{
		factor *= 10;
		i++;
	}
	c = '0' + nb / factor;
	write(fd, &c, 1);
	ft_putdec_fd_rec(nb % factor, decimals - 1, fd);
}

void	ft_putfloat_fd(float nb, int decimals, int fd)
{
	long long	factor;
	long long	fl_to_long;
	long long	int_part;
	long long	dec_part;
	int			i;

	factor = 1;
	i = decimals;
	if (fd <= 0)
		return ;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	while (decimals > 0 && i-- > 0)
		factor *= 10;
	fl_to_long = (long long)(nb * factor);
	int_part = fl_to_long / factor;
	dec_part = fl_to_long % factor;
	ft_putint_fd_rec(int_part, fd);
	if (decimals > 0)
		write(fd, ".", 1);
	ft_putdec_fd_rec(dec_part, decimals, fd);
}
