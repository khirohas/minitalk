/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirohas <khirohas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:25:01 by khirohas          #+#    #+#             */
/*   Updated: 2021/12/14 22:43:51 by khirohas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)

{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			count++;
		}
		i++;
	}
	return (count);
}

static void	*ft_free_split(size_t arrno, char **split)
{
	size_t	i;

	i = 0;
	while (i < arrno)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	return (NULL);
}

static char	**ft_put_strarray(char const *s, char c, char **split)
{
	size_t	len;
	size_t	i;
	size_t	arrno;

	i = 0;
	len = 0;
	arrno = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			len++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			split[arrno] = (char *)malloc(sizeof(char) * (len + 1));
			if (split[arrno] == NULL)
				return (ft_free_split(arrno, split));
			ft_strlcpy(split[arrno], &s[i - len + 1], len + 1);
			arrno++;
			len = 0;
		}
		i++;
	}
	split[arrno] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**split;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	if (!ft_put_strarray(s, c, split))
		return (NULL);
	return (split);
}
