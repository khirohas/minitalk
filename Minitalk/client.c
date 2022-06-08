/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:17:42 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/08 21:45:44 by keihirohash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "client.h" 
#include "libft/libft.h"

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

static bool	parse_args(struct s_args *args, int argc, char *argv[])
{
	if (!args || argc != 3 || !check_argv(argv[1]))
	{
		ft_putstr_fd("parse error", 1);
		return (false);
	}
	args->pid = ft_atoi(argv[1]);
	args->str = argv[2];
	return (true);
}

static void	send_char(int pid, char c)
{
	int	current_bit;

	current_bit = 0;
	while (current_bit < 8)
	{
		if (c & (1 << current_bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		current_bit++;
	}
}

static bool	send_string(struct s_args *args)
{
	size_t	i;

	errno = 0;
	i = 0;
	while (args->str[i] != '\0')
	{
		send_char(args->pid, args->str[i]);
		i++;
	}
	if (errno != 0)
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	struct s_args	args;

	if (!parse_args(&args, argc, argv))
		exit(1);
	if (args.pid < 100 || args.pid > 99998)
		exit(1);
	if (ft_strlen(args.str) > 10000)
		exit(1);
	if (!send_string(&args))
		exit (1);
	return (0);
}
