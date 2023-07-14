#include "../executor/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}
//restituisce in quale riga della matrice si trova la variabile
int	var_line(char *var, char **matrix)
{
	int		i;
	char	**full;

	i = 0;
	while (matrix[i])
	{
		full = ft_split(matrix[i], '=');
		if (ft_strncmp(full[0], var, ft_strlen(full[0])) == 0)
		{
			free_matrix(full);
			break ;
		}
		free_matrix(full);
		i++;
	}
	return (i);
}

char	*ft_strjoin_export(char *line)
{
	char	*quote;
	char	*decl;

	decl = ft_strjoin("declare -x ", line);
	free(line);
	quote = ft_strjoin(decl, "\"");
	free(decl);
	return (quote);
}
//Restituisce il numero di righe della matrice di char
int	ft_matrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
//Libera la matrice di char
void 	free_matrix(char **src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}