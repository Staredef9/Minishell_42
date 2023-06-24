#include "../executor/minishell.h"

void	echo(char *argument, char *option)
{
	
	if (option)
		ft_printf("%s", argument);
	//opzioni di argoment: 
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
		if (current_dir->d_name  == argument)
			break;
		current_dir = readdir(directory);
	}
	if (current_dir == NULL)
		ft_printf("nutShell: cd: hello: No such file or directory\n");
	char *slash_path = ft_strjoin(path, "/");
	char *correct_path = ft_strjoin(slash_path, current_dir->d_name);
	chdir(correct_path);
}

void	pwd()
{



}

void	export()
{
//questa prende come input stringa in formato NAME=VALUE
//mette in una matrice didue stringhe name e value 
//e poi le passa ad env nostro... 
//env deve essere rimalloccata per ospitare la nuova variabile 
}//
