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
	else if (!var)
		ft_printf("unset: not enough arguments\n");
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

char	*find_min(t_data *data)
{
	int		i;
	char	*little;

	i = 0;
	little = ft_strdup(data->envp[i]);
	while (data->envp[i])
	{
		if (ft_strcmp(little, data->envp[i]) > 0)
			little = ft_strdup(data->envp[i]);
		i++;
	}
	return (little);
}

char	*find_max(t_data *data)
{
	char	*max;
	int		i;

	i = 0;
	max = ft_strdup(data->envp[i]);
	while (data->envp[i])
	{
		if (ft_strcmp(max, data->envp[i]) < 0)
			max = ft_strdup(data->envp[i]);
		i++;
	}
	return (max);
}

char	*find_next(char *min, char *next, char *max, t_data *data)
{
	int	i;

	if (!next)
		next = max;
	i = 0;
	while (data->envp[i])
	{
		if (ft_strcmp(next, data->envp[i]) > 0 && ft_strcmp(min, data->envp[i]) < 0)
			next = ft_strdup(data->envp[i]);
		i++;
		if (ft_strncmp(data->envp[i], "_=", 2))
			i++;
	}
	if (ft_strcmp(max, next) == 0)
		return (next);
	return (find_next(min, next, max, data));
}

char	**ft_make_export(t_data *data)
{
	int		i;
	int		j;
	char	*min;
	char	*max;
	char	**matrix;

	i = 0;
	while (data->envp[i])
		i++;
	matrix = (char **)malloc(sizeof(char *) * i);
	min = find_min(data);
	max = find_max(data);
	matrix[0] = min;
	j = 0;
	while (j != i)
	{
		min = find_next(min, NULL, max, data);
		matrix[j] = min;
		j++;
	}
	matrix[j] = 0;
	//fare funzione per la formattazzione prima di restituire la matrix
	return (matrix);
}

void	export(char *comm, t_data *data)
{
	if (ft_check_value(comm))
		data->envp = add_var_to_env(data, comm);
	else if (!comm)
	{
		data->export = ft_make_export(data);
		ft_print_matrix(data->export);
	}
}
