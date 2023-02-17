NAME = server client
SOURCES = server.c client.c
PRINTF = ft_printf/ft_printf.a
LIBFT = libft/libft.a
OBJS = $(SOURCES:.c=.o)
INCLUDES = -I ft_printf/includes -I libft/includes

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)	

$(NAME): $(PRINTF) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) $(INCLUDES) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

obj/%.o: %.c
	mkdir -p obj
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	make -C libft clean
	make -C ft_printf clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft clean
	make -C ft_printf clean
	$(RM) $(NAME)

re: fclean $(NAME)