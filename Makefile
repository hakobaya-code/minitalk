NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRCS = server.C
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
SERVER_NAME =server

CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
CLIENT_NAME = client

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re:
	fclean all

$(NAME) : $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) : $(CLIENT_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIB_OBJ) -o $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJ) $(LIB)
	$(CC) $(CFALGS) $(SERVER_OBJ) $(LIB) -o $(SERVER_NAME)

$(LIB):
	$(MAKE) -c ./libft