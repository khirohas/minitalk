/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:27:11 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/14 09:48:49 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		rtn[i] = f((unsigned int)i, s[i]);
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
