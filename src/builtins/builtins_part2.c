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
//Trova la stringa con valore piu' piccolo in envp
char	*find_min(t_data *data)
{
	int		i;
	char	*little;

	i = 0;
	little = ft_strdup(data->envp[i]);
	while (data->envp[i])
	{
		if (ft_strcmp(little, data->envp[i]) > 0)
		{
			if (little)
				free(little);
			little = ft_strdup(data->envp[i]);
		}
		i++;
		if (data->envp[i] && ft_strncmp(data->envp[i], "_=", 2) == 0)
			i++;
	}
	return (little);
}
//Trova la stringa con valore piu' grande in envp
char	*find_max(t_data *data)
{
	char	*big;
	int		i;

	i = 0;
	big = ft_strdup(data->envp[i]);
	while (data->envp[i])
	{
		if (ft_strcmp(big, data->envp[i]) < 0)
		{
			if (big)
				free(big);
			big = ft_strdup(data->envp[i]);
		}
		i++;
		if (data->envp[i] && ft_strncmp(data->envp[i], "_=", 2) == 0)
			i++;
	}
	return (big);
}
//Trova la stringa col valore piu' piccolo dopo il minimo che gli viene passato
char	*find_next(char *min, char *max, t_data *data)
{
	int		i;
	char	*next;

	i = 0;
	next = ft_strdup(max);
	while (data->envp[i])
	{
		if (next && ft_strcmp(next, data->envp[i]) > 0 && \
			ft_strcmp(min, data->envp[i]) < 0)
		{
			free(next);
			next = ft_strdup(data->envp[i]);
		}
		i++;
		if (data->envp[i] && ft_strncmp(data->envp[i], "_=", 2) == 0)
			i++;
	}
	if (min)
		free(min);
	return (next);
}
//Mette tutte le stringhe della matrice nel formato di come le stampa bash
//(in sostanza: declare -x VAR_NAME="VALUE")
char	*ft_export_format(char *min)
{
	int		i;
	int		j;
	int		flag;
	char	*line;

	i = 0;
	j = 0;
	flag = 0;
	line = malloc(sizeof(char) * (ft_strlen(min) + 2));
	while (min[j])
	{
		line[i] = min[j];
		i++;
		if (min[j] == '=' && !flag)
		{
			flag = 1;
			line[i] = '\"';
			i++;
		}
		j++;
	}
	line[i] = '\0';
	return (ft_strjoin_export(line));
}
//Crea la matrice di export prendendo le variabili in ordine alfabetico da envp
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
	matrix[0] = ft_export_format(min);
	j = 1;
	while (j != i - 1)
	{
		min = find_next(min, max, data);
		matrix[j] = ft_export_format(min);
		j++;
	}
	free(max);
	if (min)
		free(min);
	matrix[j] = 0;
	return (matrix);
}

void	change_var_env(t_data *data, char *var, char *full_var)
{
	int	i;
	int	line;

	i = 0;
	line = var_line(var, data->envp);
	while (data->envp[i])
	{
		if (i == line)
		{
			free(data->envp[i]);
			data->envp[i] = ft_strdup(full_var);
		}
		i++;
	}
}

void	export(char *comm, t_data *data)
{
	char	**full;

	if (!comm)
	{
		if (data->export)
			free_matrix(data->export);
		data->export = ft_make_export(data);
		ft_print_matrix(data->export);
	}
	else if (ft_check_value(comm))
	{
		full = ft_split(comm, '=');
		if (var_line(full[0], data->envp) < ft_matrixlen(data->envp))
		{
			change_var_env(data, full[0], comm);
			free_matrix(full);
		}
		else
			data->envp = add_var_to_env(data, comm);
	}
}
