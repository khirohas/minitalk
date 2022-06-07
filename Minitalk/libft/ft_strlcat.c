/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 23:00:19 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/14 18:17:44 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char const *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strnlen(dst, size);
	src_len = ft_strlen(src);
	if (size == 0 || dst_len >= size)
		return (src_len + dst_len);
	i = 0;
	while ((i + dst_len + 1 < size) && (src[i] != '\0'))
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (src_len + dst_len);
}
