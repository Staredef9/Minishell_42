#Makefile must not relink.
#Makefile must at least contain the rules $(NAME), all, clean, fclean and re.

NAME = nat_shell

SRCS = $(wildcard ./srcs/parser/*.c) $(wildcard ./srcs/executer/*.c) $(wildcard ./srcs//*.c) $(wildcard ./srcs//*.c)

OBJS = $(SRCS:.c=.o)

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
          make -C ./libft
          make clean -C ./libft
          $(CC) $(OBJS) $(LIBFT) $(CFLGS) -o $(NAME)

%o: %.c
        $(CC) $(CFLAGS) -c $< -o $@

clean:
      $(MAKE) clean -C ./libft
      $(RM) $(OBJS)

fclean: clean
        $(MAKE) fclean -C ./libft
        $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SUFFIXES: .c .o



