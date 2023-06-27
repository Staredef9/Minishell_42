#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include "../Libft/libft.h"

typedef struct s_data
{
	char	**envp;
}   t_data;

int		ft_strcmp(char *s1, char *s2);
char	**copy_char_matrix(char **src);
void	ft_print_env(char	**matrix);
int		ft_env_search(char *arg, char **envp);
int		var_line(char *var, char **matrix);
void	free_matrix(char **src);
char    *ft_return_prompt(void);
// char	*set_str_var(char *var_name, int value);
char	**add_var_to_env(t_data *data, char *var);
void	echo(char *argument, char *option);
//void	builtins_execution(char *input, );
void	cd(char *argument);
void	pwd(void);
void    unset(char *var, t_data *data);

#endif
