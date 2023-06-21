
#include "executor/minishell.h"
//Restituisce una stringa col prompt da stampare a schermo
char	*ft_return_prompt(void)
{
	char	*user;

	user = getenv("USER");
	return (ft_strjoin(user, "@nutShell "));
}
//Loop infinito che restituisce il prompt qualsiasi cosa si scrive,
//per ora esce dal loop solo se scrivi "exit"
static void	ft_readline(char *print)
{
	char	*input;

	while (1)
	{
		input = readline(print);
		if (ft_strncmp(input, "exit", 4) == 0 || !input)
			break ;
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
	free(prompt);
	free_matrix(data->envp);
	free(data);
	return (0);
}
