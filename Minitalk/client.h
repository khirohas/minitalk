#ifndef CLIENT_H
# define CLIENT_H

# include <stdbool.h>

struct		s_args
{
	int		pid;
	char	*str;
};

bool		parse_args(struct s_args *args, int argc, char *argv[]);
void		send_message(struct s_args *args);

#endif
