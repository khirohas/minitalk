/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:46:01 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/11 04:18:31 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	dstsize;

	dstsize = (ft_strlen(s) + 1);
	dst = (char *)malloc(sizeof(char) * dstsize);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s, dstsize);
	return (dst);
}
