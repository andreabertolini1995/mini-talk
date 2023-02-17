NAME_SERVER = server
NAME_CLIENT = client
SOURCES_SERVER = server.c
SOURCES_CLIENT = client.c
PRINTF = ft_printf/ft_printf.a
LIBFT = libft/libft.a
OBJS_SERVER = $(SOURCES_SERVER:.c=.o)
OBJS_CLIENT = $(SOURCES_CLIENT:.c=.o)
INCLUDES = -I ft_printf/includes -I libft/includes

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(PRINTF) $(LIBFT) $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF) $(LIBFT) $(INCLUDES) -o $(NAME_SERVER)

$(NAME_CLIENT): $(PRINTF) $(LIBFT) $(OBJS_CLIENT) 
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) $(LIBFT) $(INCLUDES) -o $(NAME_CLIENT)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

clean:
	make -C libft clean
	make -C ft_printf clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft clean
	make -C ft_printf clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean $(NAME_SERVER) $(NAME_CLIENT)