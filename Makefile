#Makefile must not relink.
#Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

NAME = nutShell

SRCS = $(wildcard ./srcs/parser/*.c) $(wildcard ./srcs/executer/*.c) $(wildcard ./srcs//*.c) $(wildcard ./srcs//*.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./src/Libft/libft.a

LINKS = -lreadline

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./src/Libft
	make clean -C ./src/Libft
	cc -g $(OBJS) $(LINKS) $(LIBFT) $(CFLGS) -o $(NAME)

%o: %.c
	cc -g $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./src/Libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./src/Libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o



