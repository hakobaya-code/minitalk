NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
LIBFT_DIR = libft
INCLUDE = -I $(LIBFT_DIR)

all :
	make -C $(LIBFT_DIR)
	make $(CLIENT)
	make $(SERVER)

$(CLIENT) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L $(LIBFT_DIR) -l ft -o $@ $<

$(SERVER) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L $(LIBFT_DIR) -l ft -o $@ $<

#$@ はターゲット（今回はclient）
#$< はコンポーネント（今回は$(OBJS) $(LIBS)）

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

#.c.o :
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all