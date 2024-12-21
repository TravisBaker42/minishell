/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:53:25 by tbaker            #+#    #+#             */
/*   Updated: 2023/08/26 16:58:41 by tbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar(fd, n + 48);
}
/*
int	main(void)
{
	int	n = 1234567;
	int	n1 = -1234567;
	int	n2 = -2147483648;
	int	n3 = +1234567;
	int	n4 = 1234567;
	int	fd = 1;
	ft_putnbr_fd(n, fd);
	write(1, "\n", 1);
	ft_putnbr_fd(n1, fd);
	write(1, "\n", 1);
	ft_putnbr_fd(n2, fd);
	write(1, "\n", 1);
	ft_putnbr_fd(n3, fd);
	write(1, "\n", 1);
	ft_putnbr_fd(n4, fd);
	write(1, "\n", 1);
	return (0);
}*/
