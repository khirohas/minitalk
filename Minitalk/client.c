/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keihirohashi <keihirohashi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 02:17:42 by keihirohash       #+#    #+#             */
/*   Updated: 2022/06/09 11:19:48 by keihirohash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

//このプログラムはpidと文字列を格納する構造体s_argsににコマンドライン引数の情報を格納し、文字列を指定されたpidを持つプロセスに1bitづつ送信する。
//エラーハンドリングは以下の通り
//a)コマンドライン引数が三つでない場合、b)第一引数が数字以外で構成されている場合、c)pidが100以下99998以上の場合
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
