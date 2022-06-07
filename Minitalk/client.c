#include "client.h" 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include <unistd.h>

bool        check_argv(char *str_pid)
{
    size_t i;

    i = 0;
    while (str_pid[i])
    {
        if (!isdigit(str_pid[i]))
            return (false);
        else
            i++;
    }
    return (true);
}

bool        parse_args(struct s_args *args, int argc, char *argv[])
{
    if (!args || argc != 3 || !check_argv(argv[1]))
    {
        printf("parse error");
        return (false);
    }
    args->pid = atoi(argv[1]);
    args->str = argv[2];
    return (true);
}

static void send_char(int pid, char c)
{
    int     current_bit;
    
    current_bit = 0;
    while (current_bit < 8)
    {
        if (c & (1 << current_bit)) //左にcurrent bit分シフトすると、cのビット列を全て見ることができる。
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(200);
        current_bit++;
    }
}

void		send_string(struct s_args *args)
{
    size_t i;

    i = 0;
    while (args->str[i] != '\0')
    {
        send_char(args->pid, args->str[i]);
        i++;
    }
}

int         main(int argc, char *argv[])
{
    struct s_args args;
    
    if(!parse_args(&args, argc, argv))
        exit(1);
    if (args.pid < 100 || args.pid > 99998)
        exit(1);
    send_string(&args);
    return (0);
}