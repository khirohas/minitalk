/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:26:23 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/08 03:05:02 by keihirohash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdbool.h>

struct		s_args
{
	int		pid;
	char	*str;
};

bool		parse_args(struct s_args *args, int argc, char *argv[]);
void		send_string(struct s_args *args);

#endif
