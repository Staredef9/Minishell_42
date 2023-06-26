#include "../executor/minishell.h"
//toglie la variabile dalla matrice dell'env
char	**ft_remove_var(char *var, char **envp)
{
	int		i;
	int		j;
	int		rm_line;
	char	**new_env;

	i = 0;
	rm_line = var_line(var, envp);
	while (envp[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * i);
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (i == rm_line && envp[i + 1])
			i++;
		else if (i == rm_line && envp[i + 1] == 0)
		{
			j++;
			break ;
		}
		new_env[j++] = envp[i++];
	}
	new_env[j] = 0;
	//free_matrix(envp);
	return (new_env);
}

void	unset(char *var, t_data *data)
{
	if (ft_env_search(var, data->envp))
		data->envp = ft_remove_var(var, data->envp);
}