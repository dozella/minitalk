SRCS = server.c client.c
SRCS_B = server_bonus.c client_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server_bonus client_bonus

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

server_bonus: server_bonus.o libft
	$(CC) -o $@ $< -Llibft -lft

client_bonus: client_bonus.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft
    
clean:
	rm -f $(OBJS) $(OBJS_B)
	make -C libft clean
	
fclean: clean
	rm -f server client server_bonus client_bonus libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
