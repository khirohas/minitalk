/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:26:23 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/09 11:22:20 by keihirohash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "server.h"
#include "libft/libft.h"

struct		s_args
{
	int		pid;
	char	*str;
};

bool	send_string(struct s_args *args);
bool	parse_args(struct s_args *args, int argc, char *argv[]);
#endif
