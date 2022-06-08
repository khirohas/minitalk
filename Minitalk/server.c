/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:17:45 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/08 23:03:05 by keihirohash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>
#include "server.h"
#include "libft/libft.h"

//この関数はシグナルハンドラである。今回はボーナスも鑑みてsa.sigactionで送信側のpidを参照できるように一応はしているが、時間の関係上使用していない。
//この関数内で使っているのはシグナルセーフなwrite関数のみ。また変数もハンドラ内で宣言したstaticな構造体変数のみを変更している。
//具体的な動作としては、chr.characterの一番左bitから順に、シグナルがSIGUSR2の場合１、そうでない場合は0を8bit分操作している。8bitに達した時点でそれを出力。繰り返す。
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

//この関数はpidを出力する。
static void	print_pid(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}


//このプログラムは実行時に一度pidを出力し、シグナルを待つ。シグナルを受信した場合、action関数内でそのシグナルを8bitの文字情報として一文字づつ出力する。
//なお、sigactionにエラーが起きた場合exitする。
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
