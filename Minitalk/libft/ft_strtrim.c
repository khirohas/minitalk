/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 22:33:39 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/14 11:32:23 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (str == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (str[start] != '\0' && ft_strchr(set, str[start]))
		start++;
	end = ft_strlen(str);
	while (end > start && ft_strchr(set, str[end - 1]))
		end--;
	trim = (char *)malloc(sizeof(char) * (end - start + 1));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		trim[i] = str[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
