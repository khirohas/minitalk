/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:27:02 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/10 03:27:16 by keihirohash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

struct	s_character
{
	volatile sig_atomic_t	character;
	volatile sig_atomic_t	current_bit;
};

#endif