/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:32:23 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/14 11:35:10 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_putneg_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return (-n);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int		nb;
	unsigned int		exp;
	const unsigned int	base = 10;

	nb = ft_putneg_fd(n, fd);
	exp = 1;
	while (exp <= nb / base)
		exp *= base;
	while (exp > 0)
	{
		ft_putchar_fd("0123456789"[nb / exp % base], fd);
		exp /= base;
	}
}
