#include "../executor/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
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

int	ft_matrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}