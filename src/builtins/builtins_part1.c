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
	//if (argument != posizioni esistenti)
	//	ft_printf("bash: cd: hello: No such file or directory\n");

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
