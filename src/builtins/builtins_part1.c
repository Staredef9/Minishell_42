#include "../executor/minishell.h"

void	echo(char *argument, char *option, t_data *data)
{
	int	line;
	char	*full;
	char	**value;

	if (ft_strcmp(option, "$") == 0)
	{
		if (ft_env_search(argument, data->envp))
		{
			line = var_line(argument, data->envp);
			full = ft_strdup(data->envp[line]);
			value = ft_split(full, '=');
			printf("%s\n", value[1]);
			free(full);
			free_matrix(value);
		}
	}
	//opzioni di argument: 
	//$
	//$?
	else
		ft_printf("%s\n", argument);
	//come si fa a metterlo dentro le pipe e a dirgli di redirigere il suo output?
}

void	cd(char *argument)
{
	//spostati di posizione dove dice l'argument, se 
	//non esiste non fare nulla
	char path[128];
	getcwd(path, 128);

	DIR *directory = opendir(".");
	if (directory == NULL)
	{
		ft_printf("Error opening directory\n");
		return;
	}

	struct dirent *current_dir;
	current_dir = readdir(directory);
	while (current_dir)
	{
		if (ft_strncmp(current_dir->d_name, argument, ft_strlen(argument)) == 0)
			break;
		current_dir = readdir(directory);
	}
	if (current_dir == NULL)
		ft_printf("nutShell: cd: %s: No such file or directory\n", argument);
	char *slash_path = ft_strjoin(path, "/");
	char *correct_path = ft_strjoin(slash_path, current_dir->d_name);
	chdir(correct_path);
}

void	pwd(void)
{
	char path[128];
	getcwd(path, 128);
	ft_printf("%s\n", path);
}
