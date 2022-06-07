/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:08:09 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/14 11:31:51 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	size_t		i;

	ptr = NULL;
	i = 0;
	while (1)
	{
		if (s[i] == (char)c)
			ptr = &s[i];
		if (s[i] == '\0')
			return ((char *)ptr);
		i++;
	}
}
