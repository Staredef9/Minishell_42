
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
static void	ft_readline(char *print)
{
	char	*input;

	while (1)
	{
		signal(SIGINT, siginthandler);
		//signal(SIGQUIT, SIG_IGN);
		input = readline(print);
		if (ft_strncmp(input, "exit", 4) == 0 || !input)
			break ;
		// else if (ft_strncmp(input, "echo", 4) == 0 || input)
		// 	ft_printf("\n");
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
	ft_readline(prompt);
	//ft_print_env(data->envp);
	rl_clear_history();
	free(prompt);
	free_matrix(data->envp);
	free(data);
	return (0);
}
