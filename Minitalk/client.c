/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:17:42 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/09 03:51:38 by keihirohash      ###   ########.fr       */
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

//この関数はコマンドライン第一引数が数字のみかを調べる。（厳密にはINTの最大値以内かも確認する必要ありだが、オーバーフローしたとしてもpidのあたいで正常に弾かれるので良い。）
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

//この関数はコマンドライン引数がSubject通りか確認したうえで、s_args構造体にサーバーのpidと出力するべき文字列を格納する。
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

//この関数は１文字を1bitづつpidに向けて送る。ビット演算を使うことで、char型の8bit情報を１bitづつ送ることができる。
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
		usleep(500);
		current_bit++;
	}
}
//この関数は文字列をプロセスに送る。send_char内のKillでエラーが起きた場合、falseを返す。
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

//このプログラムはpidと文字列を格納する構造体s_argsににコマンドライン引数の情報を格納し、文字列を指定されたpidを持つプロセスに1bitづつ送信する。
//エラーハンドリングは以下の通り
//a)コマンドライン引数が三つでない場合、b)第一引数が数字以外で構成されている場合、c)pidが100以下99998以上の場合、
//また、安全な動作を確約するため最大出力可能文字数は10000文字とする。
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
