/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas </var/mail/khirohas>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:50:21 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/11 03:50:29 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)buf;
	while (0 < n)
	{
		if (*ptr == (unsigned char)ch)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
