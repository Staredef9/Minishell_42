
#include "executor/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_data  *data;
	data = malloc(sizeof(t_data));

	(void)ac;
	(void)av;
	data->envp = copy_char_matrix(envp);
	ft_print_env(data->envp);
	free_matrix(data->envp);
	free(data);
	return (0);
}
