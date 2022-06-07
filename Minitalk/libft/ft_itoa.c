/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:26:04 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/14 18:27:26 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_itoa(int n)
{
	char			*rtn;
	size_t			len;
	unsigned int	nb;

	len = count_len(n);
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (rtn == NULL)
		return (NULL);
	nb = ft_abs(n);
	rtn[len] = '\0';
	while (len > 0)
	{
		rtn[len - 1] = "0123456789"[nb % 10];
		nb /= 10;
		len--;
	}
	if (n < 0)
		rtn[0] = '-';
	return (rtn);
}
