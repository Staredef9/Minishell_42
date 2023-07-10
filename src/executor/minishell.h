#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include "../Libft/libft.h"

typedef struct s_data
{
	char	**envp;
	char	**export;
}   t_data;



// typedef struct	s_input
// {
// 	char **cmd_opt;
// 	char **IO;
// 	t_input *next;
// } t_input;


// typedef struct s_minishell
// {
// 	t_data	*env_ptr;
// 	//

// } t_mini	shell;





//parser 
// int		parser(char *arg_line, t_input *input);
// int		is_piped(char *arg_line);
// int		is_in_charset(char c, char *charset);
// int		input_init(t_input *input, int counter);
// char	**tokenize(char *arg_line);
// void	define_token_operator(char *cmd, int *cmd_type);
// void	define_token_type(char **cmd, int **cmd_type, int i, int *cmd_in_pipe);





//ENV 
char	**copy_char_matrix(char **src);
void	ft_print_matrix(char	**matrix);
int		ft_env_search(char *arg, char **envp);
int		var_line(char *var, char **matrix);
int		ft_matrixlen(char **matrix);
void	free_matrix(char **src);
char    *ft_return_prompt(void);
// char	*set_str_var(char *var_name, int value);
char	**add_var_to_env(t_data *data, char *var);
void	change_var_env(t_data *data, char *var, char *full_var);

//executor
int	executor_handler(char **arguments);

//export utils
char	**ft_make_export(t_data *data);
char	*ft_export_format(char *min);
char	*find_next(char *min, char *max, t_data *data);
char	*find_max(t_data *data);
char	*find_min(t_data *data);

//builtins
void	execute_builtin(char **arguments);
void	echo(char *argument, char *option, t_data *data);
void	cd(char *argument, t_data *data);
void	pwd(void);
void    unset(char *var, t_data *data);
void	export(char *comm, t_data *data);

//utils
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin_export(char *line);

//binary execution
void	execute_command(char *command, char *arg, char **PATH);







#endif
