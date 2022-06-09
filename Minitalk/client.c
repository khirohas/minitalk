/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:17:42 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/09 11:30:44 by keihirohash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char *argv[])
{
	struct s_args	args;

	if (!parse_args(&args, argc, argv))
		exit(1);
	if (args.pid < 100 || args.pid > 99998)
		exit(1);
	if (!send_string(&args))
		exit (1);
	return (0);
}
