/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:15:59 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/09 11:30:37 by keihirohash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send_char(int pid, char c)
{
	int	current_bit;

	current_bit = 0;
	while (current_bit < 8)
	{
		if (c & (1 << current_bit))
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(1);
		}
		else
		{ 
			if (kill(pid, SIGUSR1) < 0)
				exit(1);
		}
		usleep(50);
		current_bit++;
	}
}

bool	send_string(struct s_args *args)
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