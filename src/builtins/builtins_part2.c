#include "../executor/minishell.h"
//toglie la variabile dalla matrice dell'env
char	**ft_remove_var(char *var, t_data *data)
{
	int		i;
	int		j;
	int		rm_line;
	char	**new_env;

	i = 0;
	rm_line = var_line(var, data->envp);
	while (data->envp[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	j = 0;
	while (data->envp[i])
	{
		if (i != rm_line)
		{
			new_env[j] = ft_strdup(data->envp[i]);
			j++;
		}
		i++;
	}
	new_env[j] = 0;
	free_matrix(data->envp);
	return (new_env);
}

void	unset(char *var, t_data *data)
{
	if (ft_env_search(var, data->envp))
		data->envp = ft_remove_var(var, data);
}

int	ft_check_value(char *val)
{
	int	i;

	i = 0;
	while (val[i] != '=' && val[i])
	{
		if (val[i] < '0' || (val[i] > '9' && val[i] < 'A') || \
			(val[i] > 'Z' && val[i] < 'a') || val[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

void	export(char *comm, t_data *data)
{
	if (ft_check_value(comm))
		data->envp = add_var_to_env(data, comm);
}
