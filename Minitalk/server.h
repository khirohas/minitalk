#ifndef SERVER_H
# define SERVER_H

//この構造体をつかって、現在送りたい文字とbitの位置を管理する。
struct s_character
{
    char character;
    int current_bit;
};

void    display_pid(void);

#endif