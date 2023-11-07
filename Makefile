NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CLIENT_BONUS = client_bonus
CLIENT_BONUS_SRCS = client_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

SERVER = server
SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
SERVER_BONUS = server_bonus
SERVER_BONUS_SRCS = server_bonus.c
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
LIBFT_DIR = libft
INCLUDE = -I $(LIBFT_DIR)

all :
	make -C $(LIBFT_DIR)
	make $(CLIENT)
	make $(SERVER)

bonus :
	make -C $(LIBFT_DIR)
	make $(CLIENT_BONUS)
	make $(SERVER_BONUS)

$(CLIENT) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L $(LIBFT_DIR) -l ft -o $@ $<

$(CLIENT_BONUS) : $(CLIENT_BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L $(LIBFT_DIR) -l ft -o $@ $<

$(SERVER) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L $(LIBFT_DIR) -l ft -o $@ $<

$(SERVER_BONUS) : $(SERVER_BONUS_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L $(LIBFT_DIR) -l ft -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean: clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all