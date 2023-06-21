
#include "executor/minishell.h"

int	main(int ac, char **av, char **envp)
{
	//t_data  data;
	char	**matrix;

	(void)ac;
	(void)av;
	matrix = copy_char_matrix(envp);
	ft_print_env(matrix);
	ft_printf("gg\n");
	return (0);
}
