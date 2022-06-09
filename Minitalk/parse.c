/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:16:40 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/09 11:30:09 by keihirohash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	ft_atopid(const char *a)
{
	unsigned int	num;
	size_t			i;

	i = 0;
	num = 0;
	while (ft_isdigit(a[i]))
	{
		num = num * 10 + (a[i] - '0');
		i++;
	}
	if (num > INT_MAX)
		return (-1);
	return (num);
}

static bool	check_argv(char *str_pid)
{
	size_t	i;

	i = 0;

	while (str_pid[i])
	{
		if (!ft_isdigit(str_pid[i]))
			return (false);
		else
			i++;
	}
	return (true);
}

bool	parse_args(struct s_args *args, int argc, char *argv[])
{
	if (!args || argc != 3 || !check_argv(argv[1]))
	{
		ft_putstr_fd("parse error", 1);
		return (false);
	}
	args->pid = ft_atopid(argv[1]);
	if (args->pid < 0)
		return (false);
	args->str = argv[2];
	return (true);
}