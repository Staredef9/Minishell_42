#include "../executor/minishell.h"

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
