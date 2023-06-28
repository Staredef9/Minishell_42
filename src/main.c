
#include "executor/minishell.h"
//Restituisce una stringa col prompt da stampare a schermo
char	*ft_return_prompt(void)
{
	char	*user;

	user = getenv("USER");
	return (ft_strjoin(user, "@nutShell "));
}
//Se detecta il ctrl-c restituisce il prompt dopo uno "\n"
void	siginthandler(int sign)
{
	if (sign == SIGINT)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
//Loop infinito che restituisce il prompt qualsiasi cosa si scrive,
//per ora esce dal loop solo se scrivi "exit"
static void	ft_readline(t_data *data, char *print)
{
	char	*input;

	while (1)
	{
		signal(SIGINT, siginthandler);
		signal(SIGQUIT, SIG_IGN);
		input = readline(print);
		if (!input || ft_strncmp(input, "exit", 4) == 0)
			break ;
		else if (ft_strncmp(input, "env", 3) == 0)
			ft_print_env(data->envp);
		else if (ft_strncmp(input, "cd", 2) == 0)
			cd(".");
		else if (ft_strncmp(input, "pwd", 3) == 0)
			pwd();
		else if (ft_strncmp(input, "unset", 5) == 0)
			unset("tumamma", data);
		else if (ft_strncmp(input, "export", 6) == 0)
			export("tumamma=20", data);
		//add_history(input);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data  *data;
	char	*prompt;

	(void)ac;
	(void)av;
	data = malloc(sizeof(t_data));
	data->envp = copy_char_matrix(envp);
	prompt = ft_return_prompt();
	// data->envp = add_var_to_env(data, "tumamma=20");
	// ft_printf("res:%d\n", ft_env_search("tumamma", data));
	ft_readline(data, prompt);
	//ft_print_env(data->envp);
	rl_clear_history();
	//free(new_var);
	free(prompt);
	free_matrix(data->envp);
	free(data);
	return (0);
}
