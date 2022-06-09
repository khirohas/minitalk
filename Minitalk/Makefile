C_NAME = client
S_NAME = server

LIB = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address -fsanitize=undefined

C_SRCS = client.c parse.c send.c
S_SRCS = server.c

C_OBJS	=	${C_SRCS:.c=.o}
S_OBJS	=	${S_SRCS:.c=.o}

.PHONY: all
all: $(C_NAME) $(S_NAME)

$(C_NAME): $(C_OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(C_NAME) $(C_OBJS) $(LIB)

$(S_NAME): $(S_OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(S_NAME) $(S_OBJS) $(LIB)

.o: .c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	find . -name "*.o" -delete -print

.PHONY: fclean
fclean: clean
	rm -f $(C_NAME) $(S_NAME)
	rm -f $(LIB)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: all