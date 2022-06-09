/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:17:45 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/09 11:31:33 by keihirohash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	action(int signum, siginfo_t *info, void *context)
{
	static struct s_character	chr;

	(void)context;
	(void)info;
	if (signum == SIGUSR2)
		chr.character |= 1 << chr.current_bit;
	chr.current_bit++;
	if (chr.current_bit == 8)
	{
		if (chr.character != '\0')
			write(1, &chr.character, 1);
		chr.current_bit = 0;
		chr.character = 0;
	}
}

static void	print_pid(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	struct sigaction	act;

	print_pid();
	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = action;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) < 0)
		exit(1);
	if (sigaction(SIGUSR2, &act, NULL) < 0)
		exit(1);
	while (1)
		pause();
	return (0);
}
