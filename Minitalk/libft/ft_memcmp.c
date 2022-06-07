/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:02:21 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/14 11:27:31 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	const unsigned char	*u1;
	const unsigned char	*u2;

	u1 = (const unsigned char *)buf1;
	u2 = (const unsigned char *)buf2;
	while (n > 0)
	{
		if (*u1 != *u2)
			return (*u1 - *u2);
		n--;
		u1++;
		u2++;
	}
	return (0);
}
