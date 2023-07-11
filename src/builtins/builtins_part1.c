#include "../executor/minishell.h"

char	*ft_remove_dollar(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 1;
	j = 0;
	new = malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		new[j] = str[i];
		j++;
		i++;
	}
	new[j] = '\0';
	free(str);
	return (new);
}

void	echo(char *argument, char *option, t_data *data)
{
	int		line;
	char	*var;
	char	*full;
	char	**value;

	if (ft_strncmp(argument, "$", 1) == 0)
	{
		var = ft_remove_dollar(argument);
		if (ft_env_search(var, data->envp))
		{
			line = var_line(var, data->envp);
			full = ft_strdup(data->envp[line]);
			value = ft_split(full, '=');
			printf("%s", value[1]);
			if (!option)
				printf("\n");
			free(full);
			free_matrix(value);
		}
		free(var);
	}
	//opzioni di argument: 
	//$
	//$?
	else
		ft_printf("%s\n", argument);
	//come si fa a metterlo dentro le pipe e a dirgli di redirigere il suo output?
}


void	ft_replace_pwd(t_data *data, int line)
{
	char	*old;
	char	*pwd;
	char	path[128];
	char	*new_line;
	char	**value;

	old = ft_strdup(data->envp[line]);
	pwd = ft_strjoin("PWD=", getcwd(path, 128));
	change_var_env(data, "PWD", pwd);
	free(pwd);
	value = ft_split(old, '=');
	free(old);
	new_line = ft_strjoin("OLDPWD=", value[1]);
	change_var_env(data, "OLDPWD", new_line);
	free(new_line);
	free_matrix(value);
}
//spostati di posizione dove dice l'argument, se 
//non esiste non fare nulla
void	cd(char *argument, t_data *data)
{
	int		ret;

	ret = chdir(argument);
	if (ret == -1)
		ft_printf("nutShell: cd: %s: No such file or directory\n", argument);
	else
		ft_replace_pwd(data, var_line("PWD", data->envp));
}

void	pwd(void)
{
	char path[128];
	getcwd(path, 128);
	ft_printf("%s\n", path);
}
