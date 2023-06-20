
#include "executor/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_data  *data;
	int	i;

	i = 0;
	data->envp = copy_char_matrix(envp);
	//ft_print_env(data->envp);
	return (0);
}
