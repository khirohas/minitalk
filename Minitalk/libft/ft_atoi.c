/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 04:17:57 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/11 04:47:08 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || ('\t' <= c && c <= '\r'))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *a)
{
	unsigned int	num;
	size_t			i;
	int				sign;

	i = 0;
	while (ft_isspace(a[i]))
		i++;
	sign = 1;
	if ((a[i] == '+') || (a[i] == '-'))
	{
		if (a[i++] == '-')
			sign *= -1;
	}
	num = 0;
	while (ft_isdigit(a[i]))
	{
		num = num * 10 + (a[i] - '0');
		i++;
	}
	return (sign * num);
}
