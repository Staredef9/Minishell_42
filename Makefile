#Makefile must not relink.
#Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

NAME = nutShell

SRCS = $(wildcard ./srcs/parser/*.c) $(wildcard ./srcs/executer/*.c) $(wildcard ./srcs//*.c) $(wildcard ./srcs//*.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make clean -C ./libft
	cc -g $(OBJS) $(LIBFT) $(CFLGS) -o $(NAME)

%o: %.c
	cc -g $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o



