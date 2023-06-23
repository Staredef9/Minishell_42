#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/ioctl.h>
#include "../Libft/libft.h"

typedef struct s_data
{
	char	**envp;
}   t_data;


char	**copy_char_matrix(char **src);
void	ft_print_env(char	**matrix);
void	free_matrix(char **src);
char    *ft_return_prompt(void);
char	*set_str_var(char *var_name, int value);
char	**add_var_to_env(char **envp, char *var);


#endif
